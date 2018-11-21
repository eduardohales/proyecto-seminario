#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <string>
#include <sstream>
#include <math.h>

class Simulador{

public:
	//prototipos constructores
	Simulador();
    //destructor
    ~Simulador();
    //metodos
    //void inicializar();
    //void arribo(Evento *p);
    //void salida(Evento *p);
    //void generaAS(int tipo, float tasaMedia, float tiempo_actual, int source,
     //         int dest, int hops, int * path);
   // void sumaCanal(Evento);
   // void restaCanal();
   // void isfreeRoute();
    //void calculaTiempo();
    //void run();//metodo para correr el simulador
    
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

    double MU;
    double LAMBDA;
    double LAMBDAPRIMA;
    double ton;
    double toff;
    double cargaTrafico;

    float * cnxBlocked;
    float * cnxLlegadas;
    float * cnxEject;
    int canalesLibres;
    float probBloq;
    float * probUser;

   // Grafo grafo;
};
#endif