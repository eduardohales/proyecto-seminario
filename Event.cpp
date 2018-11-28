#include "Event.h"

Event::Event() {
    this->type = 0;
    this->time = 0;
    this->source = 0;
    this->dest = 0;
    this->hops = 0;
}

float Event::getTiempo() {
    return time;
}

Event::Event(int type, float time, int source, int dest, int hops, std::vector<int> path) {
    this->type = type;
    this->time = time;
    this->source = source;
    this->dest = dest;
    this->hops = hops;
    //this->path = NULL;
}
