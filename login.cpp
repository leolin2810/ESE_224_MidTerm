#include "login.h"

void loadProbeFromFile(const string &filename, Galaxy &galaxy)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open probe.txt file." << endl;
        return;
    }

    int id, sensorRows, sensorCols;
    string name;
    int x, y;

    char comma;
    string line;
    // Read the file line by line
    while (getline(file, line))
    {
        stringstream ss(line);

        // int id, sensorRows, sensorCols;
        // string name;
        // int x, y;

        // char comma; // To handle commas in the input

        // Read the probe data with proper handling of commas
        ss >> id >> comma;      // Read ID and skip the comma
        getline(ss, name, ','); // Read name until the next comma
        // cout << "\"" <<name<<"\"";
        ss >> x >> comma >> y >> comma >> sensorRows >> comma >> sensorCols;
        name.erase (std::remove (name.begin(), name.end(), ' '), name.end());
        // Create the Probe object
        Probe *probe = new Probe(name, id, sensorRows, sensorCols, x, y);
        probe->initializeSensorData(sensorRows, sensorCols);

        for (int i = 0; i < sensorRows; i++)
        {
            for (int j = 0; j < sensorCols; j++)
            {
                int value;
                ss >> value;
                probe->setSensorData(i, j, value);
            }
        }

        // Add the Probe to the linked list
        // galaxy.addProbeToLinkedList(probe);
        galaxy.addExistingProbe(*probe);
    }

    file.close(); // Close the file
}

void login(const string filename)
{
    ifstream file(filename); // open input file based on input string name

    // check if the file opens correctly
    if (file.fail())
    {
        cerr << "Fail to open " << filename << endl;
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
        cout << "Enter the username: ";
        cin >> user; // pass in username from keyboard input
        cout << "Enter the password: ";
        cin >> pass; // pass in password from keyboard input

        // compare user and pass with string stored in userarray
        if (user == userarray[0] && pass == userarray[1])
        {
            cout << "Login Success...\n"
                 << endl;
            break; // break out the infinite loop if user and password are correct
        }
        else
        { // runs the loop again until username and password are correct
            cout << "Login failed, retry!\n"
                 << endl;
        }
    }
}