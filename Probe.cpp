#include <iostream>
#include "Probe.h"

Probe::Probe() : name(""), ID(-1), dimension{-1, -1}, area(-1), position{-1, -1}
{
}

Probe::Probe(std::string n, int id, int length, int width, int x, int y)
    : name(n), ID(id), dimension{length, width}, position{x, y}
{
    calculateArea();
}

void Probe::testPrint()
{
    std::cout << name << std::endl
              << ID << std::endl;
    std::cout << "(" << dimension[0] << ", " << dimension[1] << ")" << std::endl;
    //   << dimension << std::endl
    std::cout << "(" << position[0] << ", " << position[1] << ")" << std::endl;
    //   << position << std::endl;
}

// Accessors
std::string Probe::getName() const
{
    return name;
}

int Probe::getID() const
{
    return ID;
}

int Probe::getDimension(int index) const
{
    return dimension[index];
}

int Probe::getPosition(int index) const
{
    return position[index];
}

double Probe::getArea() const
{
    return area;
}

// Mutators
void Probe::setName(std::string n)
{
    name = n;
}

void Probe::setID(int id)
{
    ID = id;
}

void Probe::setDimension(int index, int value)
{
    dimension[index] = value;
    calculateArea(); // Automatically recalculate area when dimensions are changed
}

void Probe::setPosition(int index, int value)
{
    position[index] = value;
}

// Method to calculate the area
void Probe::calculateArea()
{
    area = 2 * (dimension[0] + dimension[1]);
}

// Display probe information
void Probe::displayProbe() const
{
    std::cout << "Name: " << name << "\nID: " << ID << "\nDimensions: "
              << dimension[0] << "x" << dimension[1] << "\nArea: " << area
              << "\nPosition: (" << position[0] << ", " << position[1] << ")\n";
}

// Overloaded operators
void Probe::operator<<(const Probe &p2)
{
    name = p2.name;
    ID = p2.ID;
    dimension[0] = p2.dimension[0];
    dimension[1] = p2.dimension[1];
    position[0] = p2.position[0];
    position[1] = p2.position[1];
    area = p2.area;
}

void Probe::operator-(Probe &p2)
{
    std::swap(dimension[0], p2.dimension[0]);
    std::swap(dimension[1], p2.dimension[1]);
    std::swap(position[0], p2.position[0]);
    std::swap(position[1], p2.position[1]);
    calculateArea();
    p2.calculateArea();
}
