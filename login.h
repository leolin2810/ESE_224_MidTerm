#ifndef LOGIN_H
#define	LOGIN_H

#include "Galaxy.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void loadProbeFromFile(const string& filename, Galaxy& galaxy);
void login(const string filename);


#endif // LOGIN_H
