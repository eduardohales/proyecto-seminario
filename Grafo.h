#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>

class Grafo {
private:
    int nodos;                                  // Cant. nodos de la red. Se extraen del archivo.
    int enlaces;                                // Cant. enlaces de la red. Se extraen del archivo.
    int usuarios;                               // Cant. usuarios de la red =  nodos * (nodos - 1)
    int capacity;                               // Capacidad de cada enlace
    std::vector<std::vector<int>> dataRoute;    // Vector con las rutas para cada par de nodos.
    std::vector<std::vector<int>> pathRoute;    // Vector con los caminos entre cada par de nodos.
    int maxHops;                                // Maximo largo de ruta.
public:
    Grafo();
    void loadNetwork(int fileNumber);
    void getDataFromNetwork(std::ifstream &netFile);
    void getRouteAndPathFromNetwork(std::ifstream &netFile);
    void printData();
    void printRoute();
    void printPath();
    ~Grafo();
public:
    void setMaxHops(int maxHops);
    void setCapacity(int cap);
    int getMaxHops() const;
    int getUsuarios() const;
    int getNodos() const;
    int getCapacity() const;
    int getEnlaces() const;
    int getDataRoute(int col, int row) const;
    const std::vector<int> &getpathRoute(int row) const;

};


#endif // GRAFO_H
