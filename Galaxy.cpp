#include "Galaxy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "mergeSort.h"
using namespace std;

/*
Default Constructor, creates empty vector of Probe
*/
Galaxy::Galaxy() : gala{}
{
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

    // cout << name << id <<dim[0]<<dim[1]<<pos[0]<<pos[1];

    Probe a(name, id, dim[0], dim[1], pos[0], pos[1]);
    // cout<< "hit";
    gala.push_back(a);
}
/*
INPUT: int :index
EFFECT: None
OUTPUT: Returns the Probe at the user entered index
*/
Probe Galaxy::returnProbe(int index)
{
    return gala[index];
}
/*
INPUT: None
EFFECT: Modifies the vector of probes in alphabetical order
OUTPUT: None
*/
void Galaxy::sortByName()
{
    for (int i = 0; i < gala.size(); i++)
    {
        for (int j = 0; j + i < gala.size(); j++)
        {
            const char *temp1 = gala[i].getName().c_str();
            const char *temp2 = gala[i + j].getName().c_str();
            int longestcharcount;
            gala[i].getName().length() >= gala[i + j].getName().length() ? longestcharcount = gala[i].getName().length() : gala[i + j].getName().length();
            if (strncasecmp(temp1, temp2, longestcharcount))
            {
                Probe temp = gala[i];
                gala[i] = gala[i + j];
                gala[i + j] = temp;
            }
        }
    }

    cout << "Current Sort Order" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << setw(20) << left << gala[i].getName() << setw(7) << left << "(Name: " << gala[i].getName() << ")" << endl;
    }
}
/*
INPUT: None
EFFECT: Modifies the vector of probes in ascending order of ID number
OUTPUT: None
*/
void Galaxy::sortByID()
{
    for (int i = 0; i < gala.size(); i++)
    {
        for (int j = 0; j + i < gala.size(); j++)
        {
            if (gala[i].getID() > gala[i + j].getID())
            {
                Probe temp = gala[i];
                gala[i] = gala[i + j];
                gala[i + j] = temp;
            }
        }
    }

    cout << "Current Sort Order" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << setw(20) << left << gala[i].getName() << setw(7) << left << "(ID: " << gala[i].getID() << ")" << endl;
    }
}
/*
INPUT: None
EFFECT: Modifies the vector of probes in descending order of Area
OUTPUT: None
*/
void Galaxy::sortByArea()
{
    mergeSort3WayArea(gala, gala.size());
    cout << "Current Sort Order" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << setw(20) << left << gala[i].getName() << setw(7) << left << "(Area: " << gala[i].getArea() << ")" << endl;
    }
}
/*
INPUT: string: name
EFFECT: Searches the name in the vector of Probes
OUTPUT: Returns a default probe if not found, otherwise returns the found probe
*/
Probe Galaxy::searchProbeByName(const string &name)
{
    auto it = find_if(gala.begin(), gala.end(),
                      [&name](auto &t)
                      { return (t.getName() == name); });
    if (it == gala.end())
    {
        cout << "Probe not found" << endl;
        return Probe(); // temp return val
    }
    Probe a = *it;
    a.displayProbe();
    return a;
}
/*
INPUT: int : ID Number
EFFECT: Searches the ID in the vector of Probes
OUTPUT: Returns a default probe if not found, otherwise returns the found probe
*/
Probe Galaxy::searchProbeByID(int id)
{
    auto it = find_if(gala.begin(), gala.end(),
                      [&id](auto &t)
                      { return (t.getID() == id); });
    if (it == gala.end())
    {
        cout << "Probe not found" << endl;
        return Probe(); // temp return val
    }
    Probe a = *it;
    a.displayProbe();
    return a;
}
/*
INPUT: int: index of first probe, int: index of second probe
EFFECT: swaps the position and dimension of the Probes
OUTPUT: Void
*/
void Galaxy::swapProbeData(int idx1, int idx2)
{
    if (idx2 > gala.size() - 1 || idx1 > gala.size() - 1)
    {
        cerr << "Input index was out of range";
        return;
    }
    gala[idx1] - gala[idx2];
}
/*
INPUT: int: index of probe, int: chooses to modify dimension or position,
int: chooses x or y if probeIdx was 0, chooses length or width if probeIdx was 1,
int: value to be added at that location
EFFECT: Modifies the specified data at the specified point
OUTPUT: None
*/
void Galaxy::insertProbeData(int galaxyIdx, int probeIdx, int pos, int value)
{
    switch (probeIdx)
    {
    case 0:
        gala[galaxyIdx].setPosition(pos, value);
        break;
    case 1:
        gala[galaxyIdx].setDimension(pos, value);
        break;
    }
}
/*
INPUT: int: index of probe 1, int: index of probe 2
EFFECT: Copies the dimension data and position data from probe at idx2 to idx1
OUTPUT: None
*/
void Galaxy::copyProbe(int idx1, int idx2)
{
    if (idx2 > gala.size() - 1 || idx1 > gala.size() - 1)
    {
        cerr << "Input index was out of range";
        return;
    }
    gala[idx1] << gala[idx2];
}
/*
INPUT: int: index of desired probe
EFFECT: prints out at all data of the probe
OUTPUT: None
*/
void Galaxy::displayProbe(int idx1)
{
    gala[idx1].displayProbe();
}
/*
INPUT: None
EFFECT: Modifies the vector of probes to a random order
OUTPUT: None
*/
void Galaxy::randomizeOrder()
{

    // srand(time(NULL));
    for (int i = gala.size() - 1; i > 0; i--)
    {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<> dist(0, i);

        int random_number = dist(rng);
        int j = random_number;

        Probe temp = gala[i];
        gala[i] = gala[j];
        gala[j] = temp;
    }
    printAllNames();
}
/*
INPUT: None
EFFECT: Prints the names of all the probes
OUTPUT: None
*/
void Galaxy::printAllNames()
{
    cout << "All Probe Names" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << gala[i].getName() << endl;
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

    for (int i = 0; i < gala.size(); i++)
    {
        fou << gala[i].getName() << endl;
        fou << gala[i].getID() << endl;
        fou << gala[i].getDimension(0) << " " << gala[i].getDimension(0) << endl;
        fou << gala[i].getPosition(0) << " " << gala[i].getPosition(1) << endl
            << endl;
    }

    fou.close();
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
        cout << probe->getName() << " was added to an empty queue." << endl;
        queueFront = probe;
        queueRear = probe;
    }
    else
    {
        cout << probe->getName() << " was added to an non-empty queue." << endl;
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

SpatialTree *Galaxy::getTree()
{
    return tree;
}

Galaxy::~Galaxy()
{
    // Clean up linked list
    Probe *current = head;
    while (current)
    {
        Probe *next = current->getNextProbe();
        delete current;
        current = next;
    }

    delete tree;
}
