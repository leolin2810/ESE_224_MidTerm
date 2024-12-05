//
//  spaceObject.h
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject {
public:
    virtual void move() = 0;               // Pure virtual function for movement
    virtual void displayInfo() const = 0;  // Pure virtual function for displaying object information

    virtual ~SpaceObject() = default;      // Virtual destructor for proper cleanup of derived classes
};

#endif