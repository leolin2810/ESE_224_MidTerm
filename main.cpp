#include <iostream>
#include "spaceObjectManager.h"
#include "Probe.h"
#include "Galaxy.h"
#include <fstream>
#include <string>
#include "login.h"
#include "spcobjmnger_Test.h"

using namespace std;

int main()
{
    string filename = "user.txt"; // select user.txt as our input file
    // login(filename);
    // Arrays to store probe information

    string probe = "probe.txt";
    Galaxy stars;
    loadProbeFromFile("probe.txt", stars);

    int option;

    string nameget2;
    int uinput1, uinput2;
    int probe_location, dimension_or_area, x_or_y, val;
    int uinput3, uinput4;
    int uinput;
    bool isValid = false;

    // test(); function to verify spaceObjectManager functionality

    // stard.getTree()->insert(&a);
    // stard.getTree()->insert(&b);
    // stard.getTree()->traverseInOrder();
    // stard.getTree()->traversePreOrder();
    // stard.getTree()->traversePostOrder();

    // Loop the main menu into an infinite loop and diplay the list of options
    while (1) // Switch back to 1 to turn on
    {
        cout << endl
             << "Main Menu" << endl;

        // list of options
        cout << "1. Sort Probes by Name" << endl;
        cout << "2. Sort Probes by ID" << endl;
        cout << "3. Sort Probes by area" << endl;
        cout << "4. Randomize Probe Order" << endl;
        cout << "5. Print All Probe Names" << endl;
        cout << "6. Search Probe by Name" << endl;
        cout << "7. Search Probe by ID" << endl;
        cout << "8. Write Galaxy to File" << endl;
        cout << "9. Swap Probe Data" << endl;
        cout << "10. Insert Probe Data" << endl;
        cout << "11. Copy Probe" << endl;
        cout << "12. Display Probe" << endl;
        cout << "13. Test LinkedList" << endl;
        cout << "14. Test template function spaceObjectManager functionality" << endl;
        cout << "15. Quit" << endl;

        cout << "Enter your choice (1-13): ";
        cin >> option; // pass in value from keyboard
        cout << endl;
        // swap to different cases based on value passed into option
        switch (option)
        {
        case 1:
            stars.sortByName();
            break;
        case 2:
            stars.sortByID();
            break;
        case 3:
            stars.sortByArea();
            break;
        case 4:
            stars.randomizeOrder();
            break;
        case 5:
            stars.printAllNames();
            break;
        case 6:

            cout << "Enter the name of the desired Probe name: ";
            cin >> nameget2;
            stars.searchProbeByName(nameget2);
            break;
        case 7:
            int idNum;
            cout << "Enter the name of the desired Probe ID: ";
            cin >> idNum;
            stars.searchProbeByID(idNum);
            break;
        case 8:
            stars.writeGalaxyToFile();
            break;
        case 9:

            cout << "Enter the index of the first probe: ";
            cin >> uinput1;
            cout << "Enter the index of the second probe: ";
            cin >> uinput2;
            stars.swapProbeData(uinput1, uinput2);
            break;
        case 10:

            cout << "Enter the index of the Probe to modify: ";
            cin >> probe_location;
            cout << "Enter 0 to modify the position, Enter 1 to modify the dimension: ";
            cin >> dimension_or_area;
            cout << "Enter 0 to modify the x value or length, Enter 1 to modify the y value or width: ";
            cin >> x_or_y;
            cout << "Enter the value you'd like to add: ";
            cin >> val;
            stars.insertProbeData(probe_location, dimension_or_area, x_or_y, val);
            break;
        case 11:

            cout << "Enter the index of the first probe: ";
            cin >> uinput3;
            cout << "Enter the index of the destination probe: ";
            cin >> uinput4;
            stars.copyProbe(uinput4, uinput3);
            break;
        case 12:

            cout << "Enter the index of the probe you'd like to view: ";
            cin >> uinput;
            stars.displayProbe(uinput);
            break;
        case 13:
            cout << "What would you like to do with the linked list? \n(Note: Linked list is empty upon intialization) \n";
            cout << "1. Add to linked list\n";
            cout << "2. Remove from linked list\n";
            uinput = 0;
            
 
            cout << "Enter a choice: \n";
            cin >> uinput;
            cout << uinput;
            
            if ((uinput != 1) || (uinput != 2)){
                cout << "Invalid option\n";
                break;
            }
        case 14:
            test();
            break;
        case 15:
            cout << "Thank you for using the Galactic Explorer System. Goodbye!";
            exit(1); // exit out the system
        default:
            cout << "Invalid input, please retry";
            break;
        }
    }
    return 0;
}