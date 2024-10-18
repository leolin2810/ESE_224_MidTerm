#ifndef GALAXY_H
#define GALAXY_H

#include "Probe.h"
#include <vector>

class Galaxy {
private:
    std::vector<Probe> P1;

public:
    //Mutator
    void addProbe();
};

#endif // GALAXY_H