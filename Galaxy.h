#ifndef GALAXY_H
#define GALAXY_H

#include "Probe.h"
#include "SpatialTree.h"

class Galaxy {
private:
    //Linked list
    Probe* head;  // Point to the head of the list

    //Queue and Stack
    Probe* queueFront;
    Probe* queueRear;
    Probe* stackTop;

    //BinaryTree for spatial management
    SpatialTree* spatialTree;

public:
    //Constructor
    Galaxy();

    //Linked list methods
    void addProbeToLinkedList(Probe* probe);
    void removeProbeFromLinkedList(int id);

    //Queue methods
    void enqueueProbe(Probe* probe);
    Probe* dequeueProbe();

    //Stack methods
    void pushProbe(Probe* probe);
    Probe* popProbe();

    //SpatialTree methods
    void insertProbeSpatialTree(Probe* probe);
    Probe* searchProbeSpatialTree(int x, int y);
    void traverseSpatialTreeInorder();
    void traverseSpatialTreePreorder();
    void traverseSpatialTreePostorder();

    //Display all probes in the galaxy
    void displayAllProbes() const;

    ~Galaxy();  //Destructor
};

#endif // !GALAXY_H
