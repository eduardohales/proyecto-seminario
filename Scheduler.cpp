#include <iostream>
#include "Scheduler.h"


void Scheduler::pushEvento(Evento newEvent) {
    if (scheduler.empty()) {
        scheduler.insert(scheduler.begin(), newEvent);
        return;
    }

    std::vector<Evento>::iterator it = scheduler.begin();

    while (it != scheduler.end() && newEvent.getTime() > it->getTime())
        it++;

    scheduler.insert(it, newEvent);

}

void Scheduler::print() {
    std::cout << "--- Routes ---" << std::endl;
    for (int i = 0; i < scheduler.size(); i++) {

        std::cout << std::to_string(scheduler[i].getTime()) << ' ';
    }
    std::cout << std::endl;
}

Evento Scheduler::popEvento() {
    Evento popEvent = scheduler[0];
    scheduler.erase(scheduler.begin());
    //std::cout << popEvent.getTime() << std::endl;
    return popEvent;
}

void Scheduler::freeScheduler() {
    scheduler.clear();
}

bool Scheduler::isEmpty() {
    return this->scheduler.empty();
}
