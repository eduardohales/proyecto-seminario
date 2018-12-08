#ifndef PROYECTOSEMINARIO_GRAFO2_H
#define PROYECTOSEMINARIO_GRAFO2_H

#include <string>
#include <vector>

class Grafo {
//private:
    
public:
    
    int Nodes;                                  // Cant. Nodos de la red. Se extraen del archivo.
    int Links;                                  // Cant. Enlaces de la red. Se extraen del archivo.
    int Users;                                  // Cant. usuarios de la red =  nodos * (nodos - 1)
    int Capacity;                               // Capacidad de cada enlace
    std::vector<std::vector<int>> dataRoute;    // Vector con las rutas para cada par de nodos.
    std::vector<std::vector<int>> pathRoute;    // Vector con los caminos entre cada par de nodos.
    int MaxHops;    //Maximo largo de ruta
    int datosRed[3];
    int COUNTLCG[101];

    Grafo();
    void loadNetwork(int fileNumber);
    void getDataFromNetwork(std::ifstream &netFile);
    void getRouteAndPathFromNetwork(std::ifstream &netFile);
    void printData();
    void printRoute();
    void printPath();
};


#endif //PROYECTOSEMINARIO_GRAFO2_H
