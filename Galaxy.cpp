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

void Galaxy::addExistingProbe(Probe a)
{
    gala.push_back(a);
}
/*
INPUT: VOID
EFFECT: Prompts the user to enter the details of a probe
Contructs a Probe based on these parameters, adds it to the end of the
Galaxy objecy
OUTPUT: Void
*/
void Galaxy::addProbe()
{
    string name;
    int id, dim[2], pos[2];

    cout << "Enter the Probe Name: ";
    cin >> name;
    cout << "Enter the Probe ID: ";
    cin >> id;
    cout << "Enter the length of the probe: ";
    cin >> dim[0];
    cout << "Enter the width of the probe: ";
    cin >> dim[1];
    cout << "Enter the x position of the probe: ";
    cin >> pos[0];
    cout << "Enter the y position of the probe: ";
    cin >> pos[1];
    cout << endl;
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



/*
INPUT: None
EFFECT: Writes to a file called "Galaxy.txt"
Each probe is written in format
------------
Name
ID
Length Width
X Y

------------
OUTPUT: None
*/
void Galaxy::writeGalaxyToFile()
{
    ofstream fou("Galaxy.txt");
  fou.close();
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

    

void Galaxy::addProbeToLinkedList(Probe *probe)
{
    if (head == nullptr)
    {
        head = probe;
        // cout<< "Added to empty Linked list";
    }
    else
    {
        Probe *temp = head;
        while (temp->getNextProbe() != nullptr)
        {
            temp = temp->getNextProbe();
        }
        temp->setNextProbe(probe);
        // cout<< "Added to not empty Linked list";
    }
}

/*
********IMPORTANT**********
THE PROBE MUST BE ADDED TO THE VECTOR OF PROBES IN ORDER TO BE FOUND
THE LINKED LIST AND VECTOR OF PROBES ARE SEPARATE
ADD TO BOTH OF THEM FOR THIS FUNCTION TO WORK
DEPENDENCT ON GETID METHOD FROM GALAXY

INPUT: ID number of the desired probe to be removed
EFFECT:
3 possible effects
Linked list is empty -> Prints out a statement saying so, returning

Given ID is NOT a valid option -> GETID method will print not found, returns

Item with given ID is removed from linked list
OUTPUT: Void

*/
void Galaxy::removeProbeFromLinkedList(int id)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    Probe check = searchProbeByID(id);
    int validID = check.getID();
    if (validID == -1)
    {
        // cout << "Given ID is not a probe on the list.";
        return;
    }

    Probe *prev = nullptr;
    Probe *temp = new Probe(*head);

    // Traverse the list to find the node to delete
    while (temp != nullptr && temp->getID() != id)
    {
        prev = temp;
        temp = temp->getNextProbe();
    }
    // Unlink the node
    prev->setNextProbe(temp->getNextProbe());
    head = temp->getNextProbe();

    if (temp != nullptr && temp->getID() == id)
    {
        temp = nullptr;
        delete temp;
        return;
    }
}
/*
INPUT: Pointer to a probe
EFFECT: Adds a probe to the back of the queue
OUTPUT: Void
*/
void Galaxy::enqueueProbe(Probe *probe)
{
    if (queueFront == nullptr)
    {
        // cout << probe->getName() << " was added to an empty queue." << endl;
        queueFront = probe;
        queueRear = probe;
    }
    else
    {
        // cout << probe->getName() << " was added to an non-empty queue." << endl;
        queueRear->setNextProbe(probe);
        queueRear = probe;
    }
}

/*
INPUT: Void
EFFECT: Removes the Probe at the start of the queue
OUTPUT: A pointer to a copy of the removed Probe
*/
Probe *Galaxy::dequeueProbe()
{
    if (queueFront == nullptr)
    {
        // cout << "Can't dequeue from an empty queue." << endl;
        return nullptr;
    }
    Probe *temp = new Probe(*queueFront);
    Probe b = *temp;
    Probe *x = &b;
    queueFront = queueFront->getNextProbe();
    if (queueFront == nullptr)
    {
        queueRear = nullptr;
    }
    // cout << temp->getName() << " was removed from the queue." << endl;
    delete temp;
    return x;
}

/*
INPUT: Pointer to probe
EFFECT: Probe is added to the top of the stack
OUTPUT: Void
*/
void Galaxy::pushProbe(Probe *probe)
{
    Probe *newProbe = new Probe(*probe);
    newProbe->setNextProbe(stackTop);
    stackTop = newProbe;
    // cout << stackTop->getName() << " is the new item at the top of the stack" << endl;
}

/*
INPUT: Void
EFFECT: Probe is removed from the top of the stack, Probe added right before is set as new stackTop
OUTPUT: Pointer to a copy of the popped probe
*/
Probe *Galaxy::popProbe()
{
    if (stackTop == nullptr)
    {
        cout << "Stack is Empty" << endl;
        return nullptr;
    }
    Probe *temp = new Probe(*stackTop);
    Probe b = *temp;
    Probe *x = &b;
    stackTop->setNextProbe(stackTop->getNextProbe());
    // delete temp;
    cout << x->getName() << " was popped out of the stack." << endl;
    return x;
}
