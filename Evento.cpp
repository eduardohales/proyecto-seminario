#include "Evento.h"

Evento::Evento() {
    this->type = 0;
    this->time = 0;
    this->source = 0;
    this->dest = 0;
    this->hops = 0;
}

Evento::Evento(int type, double time, int source, int dest, int hops) {
    this->type = type;
    this->time = time;
    this->source = source;
    this->dest = dest;
    this->hops = hops;
}

Evento::Evento(int type, double time, int source, int dest, int hops, std::vector<int> path) {
    this->type = type;
    this->time = time;
    this->source = source;
    this->dest = dest;
    this->hops = hops;
    this->path = path;
}

double Evento::getTime() {
    return this->time;
}

int Evento::getType() const {
    return this->type;
}

int Evento::getHops() const {
    return this->hops;
}

const std::vector<int> &Evento::getPath() const {
    return this->path;
}

int Evento::getSource() const {
    return this->source;
}

int Evento::getDest() const {
    return this->dest;
}
