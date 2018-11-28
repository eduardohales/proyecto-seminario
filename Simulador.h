#include <string>
#include <sstream>
#include <math.h>
#include "Event.h"
#include "Scheduler.h"
#include "Grafo.h"

class Simulador{

public:
    //prototipos constructores
    Simulador();
    //destructor
    ~Simulador();
    //metodos
    void init();
    void arribo(Event *ev);
    void salida(Event *ev);
    //void generaAS(int tipo, float tasaMedia, float tiempo_actual, int source,
    //         int dest, int hops, int * path);
    // void sumaCanal(Evento);
    // void restaCanal();
    // void isfreeRoute();
    float tiempoAleatorio();
    void run();//metodo para correr el simulador

    void setllegadasTot(int llegadasTot);
    void setMU(double MU);
    void setLAMBDA(double LAMBDA);
    void setTON(double ton);
    void setTOFF(double toff);
    void setcargaTrafico(double cargaTrafico);

    double getMU();
    double getLAMBDA();
    double getLAMBDAPRIMA();
    double getton();
    double gettoff();
    double getcargaTrafico();
    int getblocked();
    int getllegadasExe();
    int getllegadasTot();
    float getProbBloq();
    float * getProbUser();

private:
    int blocked;
    int llegadasExe;
    int llegadasTot;
    int canalesLibres;
    int *seed;//Arreglo de semillas lcgrand/user

    double MU;
    double LAMBDA;
    double LAMBDAPRIMA;
    double ton;
    double toff;
    double cargaTrafico;

    float * cnxBlocked;
    float * cnxLlegadas;
    float * cnxEject;
    float probBloq;
    float * probUser;
    
    Grafo *grafo;
    Scheduler *scheduler;
};