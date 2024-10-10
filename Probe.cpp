#include <iostream>
#include "Probe.h"

Probe::Probe() : name(""), ID(-1), dimension{-1, -1}, area(-1), position{-1, -1}
{
}

void Probe::testPrint()
{
    std::cout << name << std::endl
              << ID << std::endl
              << dimension << std::endl
              << area << std::endl
              << position << std::endl;
}
