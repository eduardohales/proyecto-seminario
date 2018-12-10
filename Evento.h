#ifndef EVENT_H
#define EVENT_H

#include "vector"

class Evento {
private:
    int type;
    double time;
    int source;
    int dest;
    int hops;
    std::vector<int> path;

private:

public:
    Evento();
    Evento(int type, double time, int source, int dest, int hops);
    Evento(int type, double time, int source, int dest, int hops, std::vector<int> path);

public:
    double getTime();
    int getType() const;
    int getHops() const;
    int getSource() const;
    int getDest() const;
    const std::vector<int> &getPath() const;

};


#endif // EVENT_H
