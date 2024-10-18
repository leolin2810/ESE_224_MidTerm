//
//  Probe.hpp
//  midterm
//
//  Created by Qiang Ou on 10/16/24.
//

#ifndef PROBE_HPP
#define PROBE_HPP

#include <string>
#include <iostream>

class Probe {
private:
    std::string name;
    int ID;
    int dimension[2];  // length and width
    double area;
    int position[2];   // x and y coordinates

public:
    // Constructor
    Probe(std::string n = "", int id = -1, int length = -1, int width = -1, int x = -1, int y = -1);

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
    void operator<<(const Probe& p2);
    void operator-(Probe& p2);
};

#endif

