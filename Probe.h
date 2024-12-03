#ifndef PROBE_H
#define PROBE_H
#include <string>
#include <iostream>
#include <vector>
#include "spaceObject.h"
class Probe : public SpaceObject
{
private:
    std::string name;
    int ID, dimension[2], position[2];
    double area;

    std::vector<std::vector<int>> sensorData;
    int sensorRows, sensorCols;
    Probe *nextProbe = nullptr;

public:
    Probe();
    Probe(std::string n, int id, int length, int width, int x, int y);
    void testPrint();

    // Accessors
    std::string getName() const;
    int getID() const;
    int getDimension(int index) const;
    int getPosition(int index) const;
    double getArea() const;

    // Mutators
    void setName(std::string n);
    void setID(int id);
    void setDimension(int index, int value);
    void setPosition(int index, int value);

    // Methods
    void calculateArea();
    void displayProbe() const;

    // Overloaded operators
    void operator<<(const Probe &p2);
    void operator-(Probe &p2);

    // Override methods
    void move() override;
    void displayInfo() override;

    // Sensor Initialization
    void initializeSensorData(int rows, int cols);
    void setSensorData(int row, int col, int value);
    int getSensorData(int row, int col) const;

    // Linked List management
    void setNextProbe(Probe* next);
    Probe* getNextProbe() const;
};

#endif // PROBE_H