#include <iostream>
#include "Probe.h"

Probe::Probe() : name(""), ID(-1), dimension{-1, -1}, area(-1), position{-1, -1}
{
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
