#ifndef PROYECTOSEMINARIO_EVENT_H
#define PROYECTOSEMINARIO_EVENT_H
#include <vector>

class Event {
private:
    int type;
    float time;
    int source;
    int dest;
    int hops;
    std::vector<int> path;
public:
    Event();
    Event(int type, float time, int source, int dest, int hops, std::vector<int>path);
    float getTiempo();
};


#endif //PROYECTOSEMINARIO_EVENT_H
