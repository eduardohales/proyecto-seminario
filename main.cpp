#include <iostream>
#include "Grafo.h"
#include "simulador.h"
#include "Scheduler.h"
#include "Event.h"


int main() {
    Grafo grafo;
    grafo.loadNetwork(0);
    //grafo.printData();
    //grafo.printRoute();
    //grafo.printPath();

    double MU;//Tasa media de servicio
    double LAMBDA;//Tasa media de llegada
    double LAMBDAPRIMA;
    double ton;//tiempo medio enviando
    double toff;//tiempo medio no enviando  0
    double carga;

    Scheduler scheduler;
    Event ev;

    carga = 0.3;
    ton = 0.001;
    toff = (ton/carga)-ton;
    MU = (1.0/ton);
    LAMBDA = 1.0/(ton+toff);
    LAMBDAPRIMA = 1.0/(toff);

    Simulador *sim = new Simulador(MU, LAMBDA, LAMBDAPRIMA, ton, toff, carga);
    sim->init(grafo);
    /*for (int i = 0; i < grafo.pathRoute.size(); ++i)
    {
        scheduler.pushEvento(Event(1, i, grafo.dataRoute[i][0], grafo.dataRoute[i][1], grafo.dataRoute[i][2], grafo.pathRoute[i]));
        ev = scheduler.popEvent();
        ev.printEvent();
    }*/

    //scheduler.print();
    /*ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev = scheduler.popEvent();
    ev.printEvent();
    scheduler.freeScheduler();

    //for(int i = 0; grafo)
    //scheduler.pushEvento(Event(1, 0.3, 0, 1, 2, grafo.pathRoute[]));
    /*scheduler.pushEvento(Event(1, 1.3, 0, 1, 2));
    scheduler.pushEvento(Event(1, 1.2, 0, 1, 2));
    scheduler.pushEvento(Event(1, 0.2, 0, 1, 2));
    scheduler.pushEvento(Event(1, 1.4, 0, 1, 2));
    scheduler.pushEvento(Event(1, 0.1, 0, 1, 2));
    //scheduler.popEvent();
    //scheduler.popEvent();


    
     


    /*
    Simulador sim;
    sim.setllegadasTot(1900);
    sim.setMU(21.2);
    sim.setLAMBDA(1.2);
    sim.setTON(0.2);
    sim.setTOFF(7.7);
    sim.setcargaTrafico(1);

    std::cout<< "Llegadas totales"<<": "<<sim.getllegadasTot()<<std::endl;
    std::cout<< "MU"<<": "<<sim.getMU()<<std::endl;
    std::cout<< "Lambda"<<": "<<sim.getLAMBDA()<<std::endl;
    std::cout<< "ton"<<": "<<sim.getton()<<std::endl;
    std::cout<< "toff"<<": "<<sim.gettoff()<<std::endl;
    std::cout<< "carga de trafico"<<": "<<sim.getcargaTrafico()<<std::endl;

     */

    return 0;
}