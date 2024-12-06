#include <iostream>
#include "Probe.h"
#include <string>

void test();

void test()
{
    // Variable Declaration
    Probe a("ZgoesLast", 1, 2, 3, 4, 5);
    Probe b("AgoesFirst", 3, 3, 3, 3, 3);
    Probe c("Monkey", 0, 15, 25, 3, 3);
    SpaceObjectManager<Probe> stard;
    Probe *a_p = &a;
    Probe *b_p = &b;
    Probe *c_p = &c;

    // Check For proper object addition
    stard.addObject(a_p);
    stard.addObject(b_p);
    stard.addObject(c_p);
    stard.printAllProbeNames();

    // Check sorting by Name
    stard.sortProbesByName();
    cout << "(NameSort) ";
    stard.printAllProbeNames();

    // Check sorting by ID
    stard.sortProbesByID();
    cout << "(IDSort) ";
    stard.printAllProbeNames();

    // Check sorting by Area
    stard.sortProbesByArea();
    cout << "(AreaSort) ";
    stard.printAllProbeNames();

    // Check search functionality
    cout << "(Search for \"abc\") " <<endl;
    stard.searchProbeByName("abc");
    cout << "(Search for \"ZgoesLast\") " << endl;
    stard.searchProbeByName("ZgoesLast");

    // Check for randomization
    stard.randomizeProbeOrder();
    cout << "(RandomizedSort) ";
    stard.printAllProbeNames();
}