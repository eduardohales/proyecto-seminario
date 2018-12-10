#ifndef PROYECTOSEMINARIO_SCHEDULER_H
#define PROYECTOSEMINARIO_SCHEDULER_H

#include "Evento.h"
#include <list>
#include <vector>

class Scheduler {
private:
    std::vector<Evento> scheduler;
public:
    void pushEvento(Evento newEvent);
    Evento popEvento();
    void freeScheduler();
    void print();
    bool isEmpty();
};


#endif //PROYECTOSEMINARIO_SCHEDULER_H
