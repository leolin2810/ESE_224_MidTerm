//
//  Probe.cpp
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#include "Probe.h"
#include <iostream>

// Default Constructor: Name is "", all numerical values set to -1
Probe::Probe() : name(""), ID(-1), dimension{ -1, -1 }, area(-1), position{ -1, -1 }, nextProbe(nullptr) {}

// Constructor: User may enter values to create Probe object with specified attributes
Probe::Probe(std::string n, int id, int length, int width, int x, int y) : name(n), ID(id), dimension{ length, width }, position{ x, y }, nextProbe(nullptr) {
    calculateArea();
}

// Accessors
std::string Probe::getName() const {
    return name;
}

int Probe::getID() const {
    return ID;
}

int Probe::getDimension(int index) const {
    return dimension[index];
}

int Probe::getPosition(int index) const {
    return position[index];
}

double Probe::getArea() const {
    return area;
}

// Mutators
void Probe::setName(std::string n) {
    name = n;
}

void Probe::setID(int id) {
    ID = id;
}

void Probe::setDimension(int index, int value) {
    dimension[index] = value;
    calculateArea();
}

void Probe::setPosition(int index, int value) {
    position[index] = value;
}

// Calculate the area of the probe
void Probe::calculateArea() {
    area = static_cast<double>(dimension[0]) * static_cast<double>(dimension[1]);
}

// Display information about the probe
void Probe::displayProbe() const {
    std::cout << "Name: " << name << "\nID: " << ID << "\nDimensions: "
        << dimension[0] << " x " << dimension[1] << "\nArea: " << area
        << "\nPosition: (" << position[0] << ", " << position[1] << ")\n";
}

//ADDED THIS FUNCTION TO TEST OUT MAIN
void Probe::displayInfo() const {
    displayProbe(); //SIMPLY DO THE displayProbe AGAIN
}

// Move method
void Probe::move() {
    position[0] += 1;
    position[1] += 1;
}

// Sensor Data Methods
void Probe::initializeSensorData(int rows, int cols) {
    sensorRows = rows;
    sensorCols = cols;
    sensorData.resize(rows, std::vector<int>(cols, 0));
}

void Probe::setSensorData(int row, int col, int value) {
    if (row < sensorRows && col < sensorCols) {
        sensorData[row][col] = value;
    }
}

int Probe::getSensorData(int row, int col) const {
    if (row < sensorRows && col < sensorCols) {
        return sensorData[row][col];
    }
    return -1; // Return -1 if out of bounds
}

// Linked List Management
void Probe::setNextProbe(Probe* next) {
    nextProbe = next;
}

Probe* Probe::getNextProbe() const {
    return nextProbe;
}

// Overloaded Operators
void Probe::operator<<(const Probe& p2) {
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

void Probe::operator-(Probe& p2) {
    int temp;

    // Swap dimensions
    temp = dimension[0];
    dimension[0] = p2.dimension[0];
    p2.dimension[0] = temp;

    temp = dimension[1];
    dimension[1] = p2.dimension[1];
    p2.dimension[1] = temp;

    // Swap positions
    temp = position[0];
    position[0] = p2.position[0];
    p2.position[0] = temp;

    temp = position[1];
    position[1] = p2.position[1];
    p2.position[1] = temp;

    // Swap sensor rows and columns
    temp = sensorRows;
    sensorRows = p2.sensorRows;
    p2.sensorRows = temp;

    temp = sensorCols;
    sensorCols = p2.sensorCols;
    p2.sensorCols = temp;

    // Swap sensor data
    sensorData.swap(p2.sensorData);

    // Recalculate area
    calculateArea();
    p2.calculateArea();
}