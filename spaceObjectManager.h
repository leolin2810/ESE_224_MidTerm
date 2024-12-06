#ifndef SPACEOBJECTMANAGER_H
#define SPACEOBJECTMANAGER_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <random>
template <class T>

class SpaceObjectManager
{
private:
    std::vector<T *> objects;

public:
    void addObject(T *obj);
    T *getObject(int index);
    void sortProbesByName();
    void sortProbesByID();
    void sortProbesByArea();
    void randomizeProbeOrder();
    T *searchProbeByName(const std::string &name);
    T *searchProbeByID(int id);
    void printAllProbeNames();
};

#endif // SPACEOBJECTMANAGER_H

/*
INPUT: Pointer of the type T
EFFECT: Input is added to a vector of pointers of type T
OUTPUT: Void
*/
template <class T>
inline void SpaceObjectManager<T>::addObject(T *obj)
{
    objects.push_back(obj);
}

/*
INPUT:
EFFECT:
OUTPUT:
*/
template <class T>
inline T *SpaceObjectManager<T>::getObject(int index)
{
    if (index > objects.length() || index < 0)
    {
        std::cout << "Object out of range/Not present" << std::endl;
        return nullptr;
    }
    return objects[index];
}

/*
INPUT:
EFFECT:
OUTPUT:
*/
template <class T>
inline void SpaceObjectManager<T>::sortProbesByName()
{
    for (int i = 0; i < objects.size(); i++)
    {
        for (int j = 0; j + i < objects.size(); j++)
        {
            const char *temp1 = objects[i]->getName().c_str();
            const char *temp2 = objects[i + j]->getName().c_str();
            int longestcharcount;
            objects[i]->getName().length() >= objects[i + j]->getName().length() ? longestcharcount = objects[i]->getName().length() : objects[i + j]->getName().length();
            if (strncasecmp(temp2, temp1, longestcharcount))
            {
                T *temp = objects[i];
                objects[i] = objects[i + j];
                objects[i + j] = temp;
            }
        }
    }
}

/*
INPUT:
EFFECT:
OUTPUT:
*/
template <class T>
inline void SpaceObjectManager<T>::sortProbesByID()
{
    for (int i = 0; i < objects.size(); i++)
    {
        for (int j = 0; j + i < objects.size(); j++)
        {
            if (objects[i]->getID() > objects[i + j]->getID())
            {
                T *temp = objects[i];
                objects[i] = objects[i + j];
                objects[i + j] = temp;
            }
        }
    }
}

/*
INPUT:
EFFECT:
OUTPUT:
*/
template <class T>
inline void SpaceObjectManager<T>::sortProbesByArea()
{
    for (int i = 0; i < objects.size(); i++)
    {
        for (int j = 0; j + i < objects.size(); j++)
        {
            if (objects[i]->getArea() < objects[i + j]->getArea())
            {
                T *temp = objects[i];
                objects[i] = objects[i + j];
                objects[i + j] = temp;
            }
        }
    }
}

template <class T>
inline void SpaceObjectManager<T>::randomizeProbeOrder()
{
    for (int i = objects.size() - 1; i > 0; i--)
    {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<> dist(0, i);

        int random_number = dist(rng);
        int j = random_number;

        T *temp = objects[i];
        objects[i] = objects[j];
        objects[j] = temp;
    }
}

template <class T>
inline T *SpaceObjectManager<T>::searchProbeByName(const std::string &name)
{
    auto it = find_if(objects.begin(), objects.end(),
                      [&name](auto &t)
                      { return (t->getName() == name); });
    if (it == objects.end())
    {
        std::cout << "Probe not found" << std::endl;
        return nullptr; // temp return val
    }
    T *a = *it;
    a->displayProbe();
    return a;
}

template <class T>
inline T *SpaceObjectManager<T>::searchProbeByID(int id)
{
    auto it = find_if(objects.begin(), objects.end(),
                      [&id](auto &t)
                      { return (t->getID() == id); });
    if (it == objects.end())
    {
        std::cout << "Probe not found" << std::endl;
        return nullptr; // temp return val
    }
    T *a = *it;
    a->displayProbe();
    return a;
}

template <class T>
inline void SpaceObjectManager<T>::printAllProbeNames()
{
    std::cout << "All Probe Names" << std::endl;
    for (int i = 0; i < objects.size(); i++)
    {
        std::cout << i + 1 << ". " << objects[i]->getName() << std::endl;
    }
    std::cout << std::endl;
}
