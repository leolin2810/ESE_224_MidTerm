#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Galaxy.h"
#include "Probe.h"
#include "login.h"

using namespace std;

int main() {
    login("user.txt");

    Galaxy gal;
    loadProbeFromFile("probe.txt", gal);

    //Display probes
    cout << "Linked List of Probes (Sorted by ID):\n";
    gal.displayAllProbes();

    return 0;
}
