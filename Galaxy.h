#ifndef GALAXY_H
#define GALAXY_H
#include "Probe.h"
#include <vector>

using namespace std;


class Galaxy {
private:
    vector<Probe> gala;
    int numProbes;
public:
    void addProbe();
    Probe returnProbe(int index);
    void sortByName();
    void sortByID();
    void sortByArea();


};

#endif // GALAXY_H