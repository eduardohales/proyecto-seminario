#include "Simulador.h"
#include <math.h>
#include <iostream>

// Constructor
Simulador::Simulador() {
    probBloqueo = 0.0;
    carga = 0.3;
    Ton = 0.001;
    Toff = (Ton / carga) - Ton;
    MU = 1.0 / Ton;
    LAMBDA = 1.0 / (Ton + Toff);
    LAMBDAPRIMA = 1.0 / Toff;
    scheduler = new Scheduler();
}

// Setea el grafo en el simulador.
void Simulador::setGrafo(Grafo *grafo) {
    this->grafo = grafo;
}

// Inicializa las variables de simulacion
void Simulador::init() {
    countLCG = new int[101];

    this->usuariosBloqueados = 0;
    this->llegadasEjecutadas = 0;
    this->llegdasTotales = 0;
    this->grafo->setMaxHops(0);

    this->cnxBloqueo = new double[this->grafo->getUsuarios()];
    this->cnxLlegada = new double[this->grafo->getUsuarios()];
    this->cnxEjecutada = new double[this->grafo->getUsuarios()];

    for (int i = 0; i < this->grafo->getUsuarios(); i++) {
        this->cnxBloqueo[i] = 0.0;
        this->cnxLlegada[i] = 0.0;
        this->cnxEjecutada[i] = 0.0;
    }

    this->canalesLibres = new int[this->grafo->getEnlaces()];

    for (int i = 0; i < this->grafo->getEnlaces(); i++) {
        canalesLibres[i] = grafo->getCapacity();
    }

    int j = 0;

    for (int i = 0; i < grafo->getNodos() * grafo->getNodos(); i++) {
        int source = grafo->getDataRoute(0, i);
        int dest = grafo->getDataRoute(1, i);
        int hops = grafo->getDataRoute(2, i);

        if (source != dest) {
            if (this->grafo->getMaxHops() < hops) {
                this->grafo->setMaxHops(hops);
            }

            generarAS(j, LAMBDA, 0.0, source, dest, hops, this->grafo->getpathRoute(i));
            j++;
        }
    }
    this->prob_user = new double[this->grafo->getMaxHops()];
}


void Simulador::generarAS(int tipo, double tasaMedia, double tiempo_actual, int source, int dest, int hops, std::vector<int> path) {
    double tiempo = calcularTiempo(tipo, tasaMedia) + tiempo_actual;
    scheduler->pushEvento(Evento(tipo, tiempo, source, dest, hops, path));
}

double Simulador::calcularTiempo(int tipo, double tasaMedia) {
    double tiempo, unif;
    unif = lcgrand.lcgrand(tipo % 101);
    tiempo = (-1) * (log(1 - unif) / tasaMedia);
    return tiempo;
}

Simulador::~Simulador() {
    delete[] cnxBloqueo;
    delete[] cnxEjecutada;
    delete[] cnxLlegada;
    delete[] countLCG;
    delete[] prob_user;
    delete[] canalesLibres;
    delete scheduler;
    std::cout << "Simulador terminado" << std::endl;
}

double Simulador::getProbBloqueo() {
    return this->probBloqueo;
}

int Simulador::getLlegadasTotales() {
    return this->llegdasTotales;
}

void Simulador::Arribo(Evento evento) {
    double tiempoActual = evento.getTime();

    if (isFreeRoute((evento))) {
        restaCanal(evento);
        llegadasEjecutadas++;
        cnxEjecutada[evento.getType()]++;
        generarAS((evento.getType() + grafo->getUsuarios()), MU, tiempoActual, evento.getSource(), evento.getDest(), evento.getHops(), evento.getPath());
    } else {
        usuariosBloqueados++;
        cnxBloqueo[evento.getType()]++;
        generarAS(evento.getType(), LAMBDAPRIMA, tiempoActual, evento.getSource(), evento.getDest(), evento.getHops(), evento.getPath());
    }
    llegdasTotales = llegadasEjecutadas + usuariosBloqueados;
    cnxLlegada[evento.getType()] = cnxEjecutada[evento.getType()] + cnxBloqueo[evento.getType()];
}


void Simulador::Salida(Evento evento) {
    double tiempoActual = evento.getTime();
    generarAS((evento.getType() - grafo->getUsuarios()), LAMBDAPRIMA, tiempoActual, evento.getSource(), evento.getDest(), evento.getHops(), evento.getPath());
    sumaCanal(evento);
}


bool Simulador::isFreeRoute(Evento evento) {
    bool valor = false;
    for (int i = 0; i < evento.getHops(); i++) {
        if (canalesLibres[evento.getPath()[i]] == 1) {
            return false;
        } else {
            valor = true;
        }
    }
    return valor;
}

void Simulador::restaCanal(Evento evento) {
    for (int i = 0; i < evento.getHops(); i++) {
        if (canalesLibres[evento.getPath()[i]] == 0) {
            canalesLibres[evento.getPath()[i]] = 0;
        } else {
            canalesLibres[evento.getPath()[i]] -= 1;
        }
    }
}

void Simulador::sumaCanal(Evento evento) {
    for (int i = 0; i < evento.getHops(); i++) {
        if (canalesLibres[evento.getPath()[i]] ==  grafo->getCapacity()) {
            canalesLibres[evento.getPath()[i]] = grafo->getCapacity();
        } else {
            canalesLibres[evento.getPath()[i]] += 1;
        }
    }
}

void Simulador::calcularProbUsuario() {
    std::cout << "probuser;";
    for (int i = 1; i <= grafo->getMaxHops(); i++) {
        int k = 0;
        int w = 0;
        for (int j = 0; j < pow(grafo->getNodos(), 2); j++) {
            if (grafo->getDataRoute(0, j) == grafo->getDataRoute(1, j)) {
                w = w;
            } else {
                if (grafo->getDataRoute(2, j) == i) {
                    prob_user[i - 1] += cnxBloqueo[w] / cnxLlegada[w];
                    k++;
                }
                w++;
            }
        }
        prob_user[i - 1] = (prob_user[i - 1] / (double) k);
        std::cout << prob_user[i - 1] << ";";
    }

}


void Simulador::start() {
    while (probBloqueo <= 0.001) {
        init();

        std::cout << canalesLibres[0] << ";";

        while (llegdasTotales < pow(10, 5)) {
            Evento p = scheduler->popEvento();
            if (p.getType() < grafo->getUsuarios())
                Arribo(p);
            else
                Salida(p);
        }

        probBloqueo = (double) usuariosBloqueados / (double) llegdasTotales;
        std::cout << usuariosBloqueados << ";";
        grafo->setCapacity(grafo->getCapacity() - 1);
        scheduler->freeScheduler();
        if (probBloqueo  <= 0.001)
            free();
    }
    calcularProbUsuario();
    probBloqueo = 0.0;
}

void Simulador::free() {
    delete[] cnxBloqueo;
    delete[] cnxEjecutada;
    delete[] cnxLlegada;
    delete[] canalesLibres;
    delete[] countLCG;
    delete[] prob_user;
}
