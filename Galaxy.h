#ifndef GALAXY_H
#define GALAXY_H
#include "Probe.h"
#include "SpatialTree.h"
#include <vector>

using namespace std;

class Galaxy
{
private:
    vector<Probe> gala;
    Probe *head = nullptr;
    Probe *queueFront = nullptr;
    Probe *queueRear = nullptr;
    Probe *stackTop = nullptr;

    SpatialTree *tree;

public:
    // Default Constructor
    Galaxy();
    // Adding Probes
    void addExistingProbe(Probe a);
    void addProbe();

    // Sorting Galaxy
    void sortByName();
    void sortByID();
    void sortByArea();
    void randomizeOrder();

    // Searching through Galaxy
    Probe returnProbe(int index);
    Probe searchProbeByName(const string &name);
    Probe searchProbeByID(int id);

    // Modifying Galaxy
    void swapProbeData(int idx1, int idx2);
    void insertProbeData(int galaxyIdx, int probeIdx, int pos, int value);
    void copyProbe(int idx1, int idx2);
    void displayProbe(int idx1);

    // Exporting Galaxy
    void writeGalaxyToFile();
    void printAllNames();

    void addProbeToLinkedList(Probe *probe);
    void removeProbeFromLinkedList(int id);
    void enqueueProbe(Probe *probe);
    Probe *dequeueProbe();
    void pushProbe(Probe *probe);
    Probe *popProbe();

    SpatialTree *getTree();
    ~Galaxy();
};

#endif // GALAXY_H