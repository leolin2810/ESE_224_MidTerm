//
//  Probe.hpp
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#ifndef PROBE_HPP
#define PROBE_HPP

#include "spaceObject.hpp"
#include <string>
#include <vector>

class Probe : public SpaceObject {
private:
    std::string name;
    int ID;
    int dimension[2]; // Represents length and width
    double area;
    int position[2]; // Represents x and y coordinates
    std::vector<std::vector<int>> sensorData;
    int sensorRows, sensorCols;
    Probe* nextProbe;

public:
    // Constructors
    Probe();
    Probe(std::string n, int id, int length, int width, int x, int y);

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
    void move() override;

    // Sensor data methods
    void initializeSensorData(int rows, int cols);
    void setSensorData(int row, int col, int value);
    int getSensorData(int row, int col) const;

    // Linked list management
    void setNextProbe(Probe* next);
    Probe* getNextProbe() const;

    // Overloaded operators
    void operator<<(const Probe& p2);
    void operator-(Probe& p2);
};

#endif
