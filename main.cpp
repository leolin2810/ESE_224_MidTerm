#include <iostream>
#include "Probe.h"
#include "Galaxy.h"
#include <fstream>
#include <string>

using namespace std;

void login(string filename);
void readProbe(string filename, string name[], int id[], int length[], int width[], int x[], int y[]);

int main()
{
    string filename = "user.txt"; // select user.txt as our input file
    login(filename);              // login function

    // Arrays to store probe information
    string name[10];
    int ID[10], Length[10], Width[10], xc[10], yc[10];

    string probe = "probe.txt";
    readProbe(probe, name, ID, Length, Width, xc, yc); // reads the probe info into our arrays

    int option;

    // Loop the main menu into an infinite loop and diplay the list of options
    while (1)
    {
        cout << "Main Menu" << endl;

        // list of options
        cout << "1. Sort Probes by Name" << endl;
        cout << "2. Sort Probes by ID" << endl;
        cout << "3. Sort Probes by area" << endl;
        cout << "4. Randomize Probe Order" << endl;
        cout << "5. Print All Probe Names" << endl;
        cout << "6. Search Probe by Name" << endl;
        cout << "7. Search Probe by ID" << endl;
        cout << "8. Wire Galaxy to File" << endl;
        cout << "9. Swap Probe Data" << endl;
        cout << "10. Insert Probe Data" << endl;
        cout << "11. Copy Probe" << endl;
        cout << "12. Display Probe" << endl;
        cout << "13. Quit" << endl;

        cout << "Enter your choice (1-13): ";
        cin >> option; // pass in value from keyboard

        // swap to different cases based on value passed into option
        switch (option)
        {
        case 1:
            cout << "choice 1";
            break;
        case 2:
            cout << "choice 2";
            break;
        case 3:
            cout << "choice 3";
            break;
        case 4:
            cout << "choice 4";
            break;
        case 5:
            cout << "choice 5";
            break;
        case 6:
            cout << "choice 6";
            break;
        case 7:
            cout << "choice 7";
            break;
        case 8:
            cout << "choice 8";
            break;
        case 9:
            cout << "choice 9";
            break;
        case 10:
            cout << "choice 10";
            break;
        case 11:
            cout << "choice 11";
            break;
        case 12:
            cout << "choice 12";
            break;
        case 13:
            cout << "Thank you for using the Galactic Explorer System. Goodbye!";
            exit(1); // exit out the system
        default:
            cout << "Invalid input, please retry";
            break;
        }
    }
    return 0;
}

// Login function
void login(string name)
{
    ifstream file(name); // open input file based on input string name

    // check if the file opens correctly
    if (file.fail())
    {
        cerr << "Fail to open " << name << endl;
        return;
    }

    string user, pass;   // two string to store username and password
    string userarray[2]; // string array to store string from input file

    // loops for 2 iteration
    for (int i = 0; i < 2; i++)
    {
        file >> userarray[i]; // stores the username and password into string array
    }

    file.close(); // close the input file

    // infinite loop to re-enter the user and password if it's not correct
    while (1)
    {
        cout << "Enter the username: " << endl;
        cin >> user; // pass in username from keyboard input
        cout << "Enter the password: " << endl;
        cin >> pass; // pass in password from keyboard input

        // compare user and pass with string stored in userarray
        if (user == userarray[0] && pass == userarray[1])
        {
            cout << "Login Success..." << endl;
            break; // break out the infinite loop if user and password are correct
        }
        else
        { // runs the loop again until username and password are correct
            cout << "Login failed, retry!" << endl;
        }
    }
}

/*
Input: filename, probe name, id, length, width, x coordinate and y coordinate
Effect: Reads the probe information and store it into the arrays we entered
Output: Nothing
*/
void readProbe(string filename, string name[], int id[], int length[], int width[], int x[], int y[])
{
    ifstream file(filename);

    // check if file opens successfully opens or not
    if (file.fail())
    {
        cerr << "Fail to open " << filename << endl;
        return;
    }

    // loop for 10 iterations to store 10 probe information
    for (int i = 0; i < 10; i++)
    {
        string line; // used for getline

        string temp = ""; // initialize temporary string

        while (1)
        {                        // infinite loop
            getline(file, line); // get the entire line string from the file
            /*
            Comparison of line with temporary
            Store line into temporary string for next comparison
            If getline gets "\n", we can continue the while loop again
            */
            if (line == temp)
            {
                temp = line;
                continue;
            }
            /*
            probe.txt will have # Probe Format before the actual probe information
            when we getline "# Probe Format", we compare it with any "\n" in between
            break out the while loop and store the Probe info into arrays
            */
            else
            { // line != temp
                break;
            }
        }

        string probe;

        // getline to store the name of the probe into name array
        getline(file, name[i]);

        // stores the input file values into other arrays
        file >> id[i] >> length[i] >> width[i] >> x[i] >> y[i];
    }

    file.close(); // close the file
}