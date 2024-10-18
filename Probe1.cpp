//
//  Probe.cpp
//  midterm
//
//  Created by Qiang Ou on 10/16/24.
//

#include "Probe.hpp"

// Constructor implementation
Probe::Probe(std::string n, int id, int length, int width, int x, int y)
    : name(n), ID(id) {
    dimension[0] = length;
    dimension[1] = width;
    calculateArea();
    position[0] = x;
    position[1] = y;
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
    calculateArea();  // Automatically recalculate area when dimensions are changed
}

void Probe::setPosition(int index, int value) {
    position[index] = value;
}

// Method to calculate the area
void Probe::calculateArea() {
    area = 2 * (dimension[0] + dimension[1]);
}

// Display probe information
void Probe::displayProbe() const {
    std::cout << "Name: " << name << "\nID: " << ID << "\nDimensions: "
              << dimension[0] << "x" << dimension[1] << "\nArea: " << area
              << "\nPosition: (" << position[0] << ", " << position[1] << ")\n";
}

// Overloaded operators
void Probe::operator<<(const Probe& p2) {
    name = p2.name;
    ID = p2.ID;
    dimension[0] = p2.dimension[0];
    dimension[1] = p2.dimension[1];
    position[0] = p2.position[0];
    position[1] = p2.position[1];
    area = p2.area;
}

void Probe::operator-(Probe& p2) {
    std::swap(dimension[0], p2.dimension[0]);
    std::swap(dimension[1], p2.dimension[1]);
    std::swap(position[0], p2.position[0]);
    std::swap(position[1], p2.position[1]);
    calculateArea();
    p2.calculateArea();
}
