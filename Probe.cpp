//  Probe.cpp
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#include <iostream>
#include "Probe.h"

// Default Constructor: Name is "", all numerical values set to -1
Probe::Probe() : name(""), ID(-1), dimension{-1, -1}, area(-1), position{-1, -1}
{
}

// Constructor: User may enter values to create Probe object with specified attributes
Probe::Probe(std::string n, int id, int length, int width, int x, int y)
    : name(n), ID(id), dimension{length, width}, position{x, y}
{
    calculateArea();
}

// INPUT: Void
// EFFECT: Prints out the values of each attribute of the Probe, separated by '\n'
// OUTPUT: Void
void Probe::testPrint()
{
    std::cout << name << std::endl
              << ID << std::endl;
    std::cout << "(" << dimension[0] << ", " << dimension[1] << ")" << std::endl;
    //   << dimension << std::endl
    std::cout << "(" << position[0] << ", " << position[1] << ")" << std::endl
              << area << std::endl;
    //   << position << std::endl;
}

// Accessors

/*
INPUT: Void
EFFECT: None
OUTPUT: string, name attribute of Probe object
*/
std::string Probe::getName() const
{
    return name;
}

/*
INPUT: Void
EFFECT: None
OUTPUT: int, ID attribute of Probe object
*/
int Probe::getID() const
{
    return ID;
}

/*
INPUT: int, index of dimension
EFFECT: None
OUTPUT: int, dimension attribute of Probe object at input index
*/
int Probe::getDimension(int index) const
{
    return dimension[index];
}

/*
INPUT: int, index of position
EFFECT: None
OUTPUT: int, position attribute of Probe object at input index
*/
int Probe::getPosition(int index) const
{
    return position[index];
}

/*
INPUT: Void
EFFECT: None
OUTPUT: double, area attribute of Probe object
*/
double Probe::getArea() const
{
    return area;
}

// Mutators

/*
INPUT: string, user desired name
EFFECT: Modifies name attribute to input
OUTPUT: Void
*/
void Probe::setName(std::string n)
{
    name = n;
}

/*
INPUT: int, user desired ID
EFFECT: Modifies ID attribute to input
OUTPUT: Void
*/
void Probe::setID(int id)
{
    ID = id;
}

/*
INPUT: int, index of dimension; int, user desired value
EFFECT: Modifies dimension attribute at index to user desired value
Modifies the area accordingly
OUTPUT: Void
*/
void Probe::setDimension(int index, int value)
{
    dimension[index] = value;
    calculateArea(); // Automatically recalculate area when dimensions are changed
}

/*
INPUT: int, index of position; int, user desired value
EFFECT: Modifies position attribute at index to user desired value
OUTPUT: Void
*/
void Probe::setPosition(int index, int value)
{
    position[index] = value;
}

/*
INPUT: Void
EFFECT: Modifies area attribute to be equal to the dimensions multiplied by each other
OUTPUT: Void
*/
void Probe::calculateArea()
{
    area = double(dimension[0]) * double(dimension[1]);
}

// Display probe information
/*
INPUT: Void
EFFECT: Prints all Probe information
OUTPUT: Void
*/
void Probe::displayProbe() const
{
    std::cout << "Name: " << name << "\nID: " << ID << "\nDimensions: "
              << dimension[0] << " x " << dimension[1] << "\nArea: " << area
              << "\nPosition: (" << position[0] << ", " << position[1] << ")\n\n";
}

// Overloaded operators
/*
INPUT: Probe, probe to be copied from
EFFECT: Copies the attributes of the input probe to the leftmost probe
OUTPUT: Void
*/
void Probe::operator<<(const Probe &p2)
{
    name = p2.name;
    ID = p2.ID;
    dimension[0] = p2.dimension[0];
    dimension[1] = p2.dimension[1];
    position[0] = p2.position[0];
    position[1] = p2.position[1];
    area = p2.area;
    sensorRows = p2.sensorRows;
    sensorCols = p2.sensorCols;
    sensorData = p2.sensorData;
    nextProbe = p2.nextProbe;
}

/*
INPUT: Probe, probe to be swapped with
EFFECT: Swaps the attributes of the input probe to the leftmost probe
OUTPUT: Void
*/
void Probe::operator-(Probe &p2)
{
    std::swap(dimension[0], p2.dimension[0]);
    std::swap(dimension[1], p2.dimension[1]);
    std::swap(position[0], p2.position[0]);
    std::swap(position[1], p2.position[1]);
    int temp = sensorRows;
    sensorRows = p2.sensorRows;
    p2.sensorRows = temp;

    temp = sensorCols;
    sensorCols = p2.sensorCols;
    p2.sensorCols = temp;

    // Swap sensor data
    sensorData.swap(p2.sensorData);
    calculateArea();
    p2.calculateArea();
}

/*
INPUT: Void
EFFECT: Overrides the virtual function of displayInfo with specifcally displaying Probes
OUTPUT: Void
*/
void Probe::displayInfo()
{
    displayProbe();
}

/*
INPUT: Void
EFFECT: Overrides the virtual function of move with simple funx that shifts the coordinates of probe by prompted amounts
OUTPUT: Void
*/
void Probe::move()
{
    int x;
    int y;
    std::cout << "Enter an amount to shift the x coord: ";
    std::cin >> x;
    std::cout << "Enter an amount to shift the y coord: ";
    std::cin >> y;

    position[0] = position[0] + x;
    position[1] = position[1] + y;
}

/*
INPUT: 2 ints, one specifying # of rows, the other # of columns
EFFECT: Modifies the value of sensorColumns, sensorRows, and initializes the size of sensorData to the range rows * columns
OUTPUT: Void
*/
void Probe::initializeSensorData(int rows, int cols)
{
    sensorRows = rows;
    sensorCols = cols;

    sensorData.resize(rows, std::vector<int>(cols));

    // Uncomment below to verify sensorData size
    // for (int i = 0; i < sensorRows; i++)
    // {
    //     for (int j = 0; j < sensorCols; j++)
    //     {
    //         sensorData[i][j] = 0;
    //         std::cout << sensorData[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

/*
INPUT: 3 ints, the row and the column of the sensorData to be modified, the value to be modified to
EFFECT: Sets the value at row column to be equal to the user input. Rows and columns are counted from 1, not 0
OUTPUT: Void
*/
void Probe::setSensorData(int row, int col, int value)
{
    if (row < 0 || row > sensorRows || col < 0 || col > sensorCols)
    {
        std::cout << "Entered location is out of range of the sensor.";
        return;
    }
    sensorData[row - 1][col - 1] = value;

    // Uncomment to verify position
    // for (int i = 0; i < sensorRows; i++)
    // {
    //     for (int j = 0; j < sensorCols; j++)
    //     {
    //         std::cout << sensorData[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

/*
INPUT: 2 ints, one specifying the row, the other the column
EFFECT: Will print out a statement if input search vals are out of range
OUTPUT: -1 if the row and cols are out of range, otherwise the value at the specified position
*/
int Probe::getSensorData(int row, int col) const
{
    if (row <= 0 || row > sensorRows || col <= 0 || col > sensorCols)
    {
        std::cout << "Entered location is out of range of the sensor.";
        return -1;
    }
    return sensorData[row - 1][col - 1];
}

/*
INPUT: 1 Probe Pointer
EFFECT: Modifies the *nextProbe to a specified pointer
OUTPUT: void
*/
void Probe::setNextProbe(Probe *next)
{
    nextProbe = next;
}

/*
INPUT: void
EFFECT: None
OUTPUT: returns the pointer to the next probe
*/
Probe *Probe::getNextProbe() const
{
    return nextProbe;
}
