#include <iostream>
#include <fstream>
#include <sstream>
#include "Grafo.h"


Grafo::Grafo() {
    Users = 0;
    Nodes = 0;
    Links = 0;
    MaxHops = 0;
    Capacity = 0;
}

// Carga la informacion de la red a partir del archivo de entrada.
void Grafo::loadNetwork(int fileNumber) {
    std::ifstream netFile;
    switch (fileNumber) {
        case 0:
            netFile.open("./EuroCore.rut");
            Capacity = 8;
            std::cout << "--- EuroCore.rut ---" << std::endl;
            break;
        case 1:
            netFile.open("../EON.rut");
            Capacity = 20;
            std::cout << "--- EON.rut ---" << std::endl;
            break;
        case 2:
            netFile.open("../ArpaNet.rut");
            Capacity = 25;
            std::cout << "--- ArpaNet.rut ---" << std::endl;
            break;
        case 3:
            netFile.open("../EuroLarge.rut");
            Capacity = 47;
            std::cout << "--- EuroLarge.rut ---" << std::endl;
            break;
        case 4:
            netFile.open("../NSFNet.rut");
            Capacity = 15;
            std::cout << "--- NSFNet.rut ---" << std::endl;
            break;
        default:
            netFile.open("UKNet.rut");
            Capacity = 21;
            std::cout << "--- UKNet.rut ---" << std::endl;
            break;
    }

    getDataFromNetwork(netFile);
    getRouteAndPathFromNetwork(netFile);

    netFile.close();
}


// Lee las primeras 3 lineas del archivo y las almacena en el arreglo datosRed[]
void Grafo::getDataFromNetwork(std::ifstream &netFile) {
    std::string line;

    if (netFile.is_open()) {
        for (int i = 0; i < 3; i++) {
            std::stringstream ss;
            getline(netFile, line);
            ss << line;

            while (!ss.eof()) {
                int data;
                std::string temp;
                ss >> temp;
                if (std::stringstream(temp) >> data) {
                    datosRed[i] = data;
                }

            }
        }
    }
    Nodes = datosRed[1];
    Users = Nodes * (Nodes - 1);
    Links = datosRed[2];
}

void Grafo::getRouteAndPathFromNetwork(std::ifstream &netFile) {
    std::string line;

    if (netFile.is_open()) {

        // Salta lineas sin utilizar.
        for (int i = 0; i < 3; i++) {
            getline(netFile, line);
        }

        while(!netFile.eof()) {
            std::stringstream ss;
            getline(netFile, line);
            ss << line;

            // Lee las rutas.
            std::vector<int> routeVector;
            for (int i = 0; i < 3; i++) {
                int data;
                ss >> data;
                routeVector.push_back(data);
            }

            // Lee los pahts.
            std::vector<int> pathVector;
            while (!ss.eof()) {
                int data;
                ss >> data;
                pathVector.push_back(data);
            }
            this->dataRoute.push_back(routeVector);
            this->pathRoute.push_back(pathVector);
        }
    }
}

void Grafo::printData() {
    std::cout << "Users: " << std::to_string(Users) << std::endl;
    std::cout << "Nodes: " << std::to_string(Nodes) << std::endl;
    std::cout << "Links: " << std::to_string(Links) << std::endl;
}

void Grafo::printRoute() {
    std::cout << "--- Routes ---" << std::endl;
    for (int i = 0; i < dataRoute.size(); i++) {
        std::vector<int> routes = dataRoute[i];
        for (int j = 0; j < routes.size(); j++) {
            std::cout << std::to_string(routes[j]) << ' ';
        }
        std::cout << std::endl;
    }
}

void Grafo::printPath() {
    std::cout << "--- Paths ---" << std::endl;
    for (int i = 0; i < pathRoute.size(); i++) {
        std::vector<int> paths = pathRoute[i];
        if (!paths.empty()) {
            for (int j = 0; j < paths.size(); j++) {
                std::cout << std::to_string(paths[j]) << ' ';
            }
        }
        else {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

