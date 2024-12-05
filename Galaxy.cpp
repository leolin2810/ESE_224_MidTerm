#include "Galaxy.h"
#include <iostream>

//Constructor, initialize pointers to nullptr
Galaxy::Galaxy() : head(nullptr), queueFront(nullptr), queueRear(nullptr), stackTop(nullptr), spatialTree(new SpatialTree()) {}

//Linked list
//Add probes to the linked list in the order of their IDs.
void Galaxy::addProbeToLinkedList(Probe* probe) {
    //Check if list is empty or new probe ID is smaller than the head ID
    if (!head || head->getID() > probe->getID()) {
        probe->setNextProbe(head);
        head = probe;
    }
    else { 
        Probe* current = head;
        //When current does not satisfy the while loop, exit
        while (current->getNextProbe() && current->getNextProbe()->getID() < probe->getID()) {
            current = current->getNextProbe();
        }
        //Insert the probe after finding the right position
        probe->setNextProbe(current->getNextProbe());
        current->setNextProbe(probe); 
    }
}

//Remove a probe from the linked list by its ID.
void Galaxy::removeProbeFromLinkedList(int id) {
    Probe* current = head;
    Probe* previous = nullptr;

    //Traverse the list to find the probe with the given ID
    while (current && current->getID() != id) {
        previous = current;
        current = current->getNextProbe();
    }

    if (current) { //Found the probe
        if (previous) { //Linked the previous probe to next
            previous->setNextProbe(current->getNextProbe());
        }
        else { //Edge case if the head is being removed, update head
            head = current->getNextProbe();
        }
        delete current; //Remove the probe
    }
    else { //If probe not found, print error message
        std::cout << "Probe with ID " << id << " not found in the linked list.\n";
    }
}

//Queue
//Add a probe to the rear of the queue.
void Galaxy::enqueueProbe(Probe* probe) {
    if (!queueRear) {
        //If the queue is empty, both front and rear point to the new probe
        queueFront = queueRear = probe;
    }
    else { //If not empty
        queueRear->setNextProbe(probe); //Link current rear to new probe
        queueRear = probe; //Update rear
    }
}

//Remove a probe from the front of the queue and return it
Probe* Galaxy::dequeueProbe() {
    if (!queueFront) return nullptr; //Return null if queue is empty

    Probe* temp = queueFront; //Save front queue for return
    queueFront = queueFront->getNextProbe(); //Update the front of the queue to point to the next probe

    if (!queueFront) queueRear = nullptr; //If queue is empty, set rear to nullptr

    temp->setNextProbe(nullptr);  //Disconnect the probe from the queue
    return temp; //Return front queue
}

//Stack
//Push a probe onto the stack
void Galaxy::pushProbe(Probe* probe) {
    probe->setNextProbe(stackTop); //Link the new probe to the current top of the stack
    stackTop = probe; //Update the top of the stack
}

//Pop a probe from the top of the stack and return it
Probe* Galaxy::popProbe() {
    if (!stackTop) return nullptr; //Return null if stack is empty

    Probe* temp = stackTop; //Save top stack for return
    stackTop = stackTop->getNextProbe(); //Update the top to the next pointer

    temp->setNextProbe(nullptr);  //Disconnect from the stack
    return temp; //Return saved stack
}

//SpatialTree management
//Insert a probe into the SpatialTree based on its position.
void Galaxy::insertProbeSpatialTree(Probe* probe) {
    spatialTree->insert(probe);
}

//Search for a probe by its (x, y) position.
Probe* Galaxy::searchProbeSpatialTree(int x, int y) {
    return spatialTree->search(x, y);
}

//Traverse inorder and display the probe
void Galaxy::traverseSpatialTreeInorder() {
    spatialTree->traverseInOrder();
}

//Traverse preorder and display the probe
void Galaxy::traverseSpatialTreePreorder() {
    spatialTree->traversePreOrder();
}

//Traveerse postorder and display the probe
void Galaxy::traverseSpatialTreePostorder() {
    spatialTree->traversePostOrder();
}

//Display all probes in the Galaxy
void Galaxy::displayAllProbes() const {
    Probe* current = head;
    while (current) {
        current->displayProbe();
        current = current->getNextProbe();
    }
}

//Destructor
Galaxy::~Galaxy() {
    //Clean up linked list
    Probe* current = head;
    while (current) {
        Probe* next = current->getNextProbe();
        delete current;
        current = next;
    }
    delete spatialTree;
}