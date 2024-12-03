#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject
{
public:
    virtual void move() = 0;
    virtual void displayInfo() = 0;
};

#endif //SPACEOBJECT_H