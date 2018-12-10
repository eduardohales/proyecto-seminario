#include <iostream>
#include "Grafo.h"
#include "Simulador.h"
#include "Scheduler.h"
#include <math.h>

int main() {
    Grafo grafo;
    grafo.loadNetwork(0);
    grafo.printRoute();

    Simulador simulador;
    simulador.setGrafo(&grafo);

    simulador.start();
    return 0;
}
