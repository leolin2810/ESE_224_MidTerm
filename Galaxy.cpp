#include "Galaxy.h"
#include <iostream>
#include <fstream>
using namespace std;

Galaxy::Galaxy() : gala{}
{
}

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

Probe Galaxy::returnProbe(int index)
{
    return gala[index];
}

void Galaxy::sortByName()
{
}

void Galaxy::sortByID()
{
}

void Galaxy::sortByArea()
{
}

Probe Galaxy::searchProbeByName(const string &name)
{
    return Probe();
}

Probe Galaxy::searchProbeByID(int id)
{
    return Probe();
}

void Galaxy::swapProbeData(int idx1, int idx2)
{
    if (idx2 > gala.size() - 1 || idx1 > gala.size() - 1)
    {
        cerr << "Input index was out of range";
        return;
    }
    gala[idx1] - gala[idx2];
}

void Galaxy::insertProbeData(int galaxyIdx, int probeIdx, int value)
{
}

void Galaxy::copyProbe(int idx1, int idx2)
{
    if (idx2 > gala.size() - 1 || idx1 > gala.size() - 1)
    {
        cerr << "Input index was out of range";
        return;
    }
    gala[idx1] << gala[idx2];
}

void Galaxy::displayProbe(int idx1)
{
    gala[idx1].displayProbe();
}

void Galaxy::randomizeOrder()
{
}

void Galaxy::printAllNames()
{
    cout << "All Probe Names" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << gala[i].getName() << endl;
    }
}

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
