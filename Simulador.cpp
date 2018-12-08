#include "lcgrand.h"
#include "simulador.h"

Simulador::Simulador(){
    this->blocked = 0;
    this->llegadasExe = 0;
    this->llegadasTot = 0;
    this->MU=0;
    this->LAMBDA=0;
    this->LAMBDAPRIMA=0;
    this->ton=0;
    this->toff = 0;
    this->cargaTrafico = 0;
    this->canalesLibres = 0;
    this->probBloq = 0;
    /*this->cnxBlocked = NULL;
    this->cnxLlegadas = NULL;
    this->cnxEject = NULL;
    this->probUser = NULL;
    this->seed = NULL;
    this->scheduler = NULL;*/
}

Simulador::Simulador(double MU, double LAMBDA, double LAMBDAPRIMA, double ton, double toff, double cargaTrafico){
    this->blocked = 0;
    this->llegadasExe = 0;
    this->llegadasTot = 0;
    this->probBloq=0;
    this->MU = MU;
    this->LAMBDA = LAMBDA;
    this->LAMBDAPRIMA = LAMBDAPRIMA;
    this->ton = ton;
    this->toff = toff;
    this->cargaTrafico = cargaTrafico;
   
}
Simulador::~Simulador(){}
//metodos


float Simulador::tiempoAleatorio(int tipo, float tasaMedia){
    float time, unif;
    unif = lcgrand(*(this->seed+tipo));
    time = (-1)*(log(1-unif))/tasaMedia;

    return time;
}

//se inicializa el scheduler y variables que dependen del grafo
void Simulador::init(Grafo &grafo){
    this->grafo = grafo;
    this->grafo.printData();
    //grafo.printRoute();
    int j = 0;
    Event ev;

    for (int i = 0; i < this->grafo.pathRoute.size(); ++i)
    {
        std:: cout<<"entro";
        if (this->grafo.dataRoute[i][0] == this->grafo.dataRoute[i][1])
        {       
            j=j;
        }
        else{
            (this->scheduler).pushEvento(Event(j, tiempoAleatorio(j, this->LAMBDA), grafo.dataRoute[j][0],
            grafo.dataRoute[j][1], grafo.dataRoute[j][2], grafo.pathRoute[j]));
            ev = scheduler.popEvent();
            ev.printEvent(); 
        }
        j++; 
    }

    this->canalesLibres = new int[grafo.Links];
    for (int i = 0; i < grafo.Links; ++i)
    {           
        canalesLibres[i] = grafo.Capacity;
    }
    this->seed = new int[grafo.Users * 2];
    j=0;
    for (int i = 0; i < grafo.Users*2; ++i)
    {
        if(j==100) j=0;
        else ++j;
        seed[i]=j;
    }
    //this->cnxBlocked = NULL;
    //this->cnxLlegadas = NULL;
    //this->cnxEject = NULL;
    //this->probUser = NULL;
}
/*    free(popEvent);
}
//void Simulador::arribo(Event *ev){
   /* int newType;
    float currentTime, newTime;
    newType = (ev->type)-grafo.getUser();
    currentTime = ev->tiempo;
    newTime = currentTime + tiempoAleatorio(newType, this->MU);

    if (isfreeRoute())
    {
        /* code */
    /*}
    else{

    }*/
//}
/*void Simulador::salida(Event *ev){
    int newType;
    float currentTime, newTime;
    newType = (ev->type)-grafo.getUser();
    currentTime = ev->tiempo;
    newTime = currentTime + tiempoAleatorio(newType, this->LAMBDAPRIMA);
    scheduler.pushEvento(new Event(newType,newTime, ev->source, ev->dest, ev->hops, ev->path));
    //sumarCanal();
}*/

double Simulador::getMU(){
    return this->MU;
}
double Simulador::getLAMBDA(){
    return this->LAMBDA;
}
double Simulador::getLAMBDAPRIMA(){
    return this->LAMBDAPRIMA;
}
double Simulador::getton(){
    return this->ton;
}
double Simulador::gettoff(){
    return this->toff;
}
double Simulador::getcargaTrafico(){
    return this->cargaTrafico;
}
int Simulador::getblocked(){
    return this->blocked;
}
int Simulador::getllegadasExe(){
    return this->llegadasExe;
}
int Simulador::getllegadasTot(){
    return this->llegadasTot;
}
float Simulador::getProbBloq(){
    return this->probBloq;
}
float * Simulador::getProbUser(){
    return this->probUser;
}
void Simulador::setllegadasTot(int llegadasTot){
    this->llegadasTot = llegadasTot;
}
void Simulador::setMU(double MU){
    this->MU = MU;
}
void Simulador::setLAMBDA(double LAMBDA){
    this->LAMBDA = LAMBDA;
}
void Simulador::setTON(double ton){
    this->ton = ton;
}
void Simulador::setTOFF(double toff){
    this->toff = toff;
}
void Simulador::setcargaTrafico(double cargaTrafico){
    this->cargaTrafico = cargaTrafico;
}



