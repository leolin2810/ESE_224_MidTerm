
//
//  spaceObject.h
//  FinalProject
//
//  Created by Qiang Ou on 11/30/24.
//

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject
{
public:
    virtual void move() = 0;
    virtual void displayInfo() = 0;
  
  virtual ~SpaceObject() = default;
};

#endif //SPACEOBJECT_H

