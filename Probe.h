#ifndef PROBE_H
#define PROBE_H
#include <string>
class Probe
{
private:
    std::string name;
    int ID, dimension[2], position[2];
    double area;

public:
    Probe();
    void testPrint();
    
};

#endif // PROBE_H