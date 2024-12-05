//
//  spaceObject.hpp
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#ifndef SPACEOBJECT_HPP
#define SPACEOBJECT_HPP

class SpaceObject {
public:
    virtual void move() = 0;               // Pure virtual function for movement
    virtual void displayInfo() const = 0;  // Pure virtual function for displaying object information

    virtual ~SpaceObject() = default;      // Virtual destructor for proper cleanup of derived classes
};

#endif
