#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Grafo.h"
#include "Scheduler.h"
#include "Lcgrand.h"

class Simulador {
private:
    int usuariosBloqueados;
    int llegadasEjecutadas;
    int llegdasTotales;
    double MU;
    double LAMBDA;
    double LAMBDAPRIMA;
    double Ton;
    double Toff;
    double carga;
    double probBloqueo;

    double *cnxBloqueo;
    double *cnxLlegada;
    double *cnxEjecutada;
    int *canalesLibres;
    double *prob_user;

    Lcgrand lcgrand;
    int *countLCG;
    int *seed;

    int iteraciones;


public:
    Grafo *grafo;
    Scheduler *scheduler;

public:
    Simulador();
    void setGrafo(Grafo *grafo);
    void init();
    void start();
    void generarAS(int tipo, double tasaMedia, double tiempo_actual, int source, int dest, int hops, std::vector<int> path);
    double calcularTiempo(int tipo, double tasaMedia);
    void Arribo(Evento evento);
    void Salida(Evento evento);
    bool isFreeRoute(Evento evento);
    void restaCanal(Evento evento);
    void sumaCanal(Evento evento);
    void calcularProbUsuario();
    void free();
    ~Simulador();

// Getters y Setters.
public:
    double getProbBloqueo();
    int getLlegadasTotales();
    void setIteraciones(int it);
};


#endif //SIMULADOR_H
