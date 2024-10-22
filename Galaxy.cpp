#include "Galaxy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "mergeSort.h"
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

void Galaxy::sortByArea()
{
    mergeSort3WayArea(gala, gala.size());
    cout << "Current Sort Order" << endl;
    for (int i = 0; i < gala.size(); i++)
    {
        cout << i + 1 << ". " << setw(20) << left << gala[i].getName() << setw(7) << left << "(Area: " << gala[i].getArea() << ")" << endl;
    }
}

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

void Galaxy::swapProbeData(int idx1, int idx2)
{
    if (idx2 > gala.size() - 1 || idx1 > gala.size() - 1)
    {
        cerr << "Input index was out of range";
        return;
    }
    gala[idx1] - gala[idx2];
}

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

    // // srand(time(NULL));
    // for (int i = gala.size() - 1; i > 0; i--)
    // {
    //     std::mt19937 rng(std::random_device{}());
    //     std::uniform_int_distribution<> dist(0, gala.size());

    //     auto random_number = dist(rng);
    //     // int j = rand() % (i + 1);
    //     Probe temp = gala[i];
    //     gala[i] = gala[j];
    //     gala[j] = temp;
    // }
    // printAllNames();
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
