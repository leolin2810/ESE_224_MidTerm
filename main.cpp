#include <iostream>
#include "Probe.h"
#include "Galaxy.h"

using namespace std;

int main()
{
    Galaxy g1;

    g1.addProbe();
    g1.addProbe();

    g1.sortByName();
    // g1.insertProbeData(0)
    // g1.addProbe();

    // g1.writeGalaxyToFile();

    // g1.displayProbe(0);
    // g1.displayProbe(1);

    // g1.copyProbe(0,1);

    // g1.displayProbe(0);
    // g1.displayProbe(1);

    // g1.printAllNames();
    // g1.displayProbe(1);

    // g1.addProbe();
    // g1.returnProbe(1).testPrint();

    // Probe a("mam", 3, 3, 5, 6, 7);
    // Probe b;
    // a.displayProbe();

    // Accessors Verified
    // cout << "ID: " << a.getID() << endl;
    // cout << "Name: " << a.getName() << endl;
    // cout << "Dimension: " << a.getDimension(0) << ", " << a.getDimension(1) << endl;
    // cout << "Position: " << a.getPosition(0) << ", " << a.getPosition(1) << endl;
    // cout << "Area: " << a.getArea() << endl;

    // Mutators Verified
    // a.setName("dunnit");
    // a.setID(67);
    // a.setDimension(0, 27);
    // a.setPosition(1, 3);

    // << overload verified
    // b.displayProbe();
    // b << a;
    // b.displayProbe();

    // - overload verified
    // a.displayProbe();
    // b.displayProbe();
    // b - a;
    // a.displayProbe();
    // b.displayProbe();
}