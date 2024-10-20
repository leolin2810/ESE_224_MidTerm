#ifndef GALAXY_H
#define GALAXY_H
#include "Probe.h"
#include <vector>

using namespace std;


class Galaxy {
private:
    vector<Probe> gala;
public:
    Galaxy();
    void addProbe();
    Probe returnProbe(int index);
    void sortByName();
    void sortByID();
    void sortByArea();
    Probe searchProbeByName(const string& name);
    Probe searchProbeByID(int id);
    void swapProbeData(int idx1, int idx2);
    void insertProbeData(int galaxyIdx, int probeIdx, int value);
    void copyProbe(int idx1, int idx2);
    void displayProbe(int idx1);
    void randomizeOrder();
    void printAllNames();
    void writeGalaxyToFile();



};

#endif // GALAXY_H