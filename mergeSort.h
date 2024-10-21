#include <bits/stdc++.h>
#include <vector>
#include "Probe.h"
using namespace std;

void merge(vector<Probe> &gArray, int low, int mid1,
           int mid2, int high, vector<Probe> &destArray);

void mergeSort3WayRec(vector<double> &gArray, int low,
                      int high, vector<Probe> &destArray);

void mergeSort3WayArea(vector<Probe> &gArray, int n);
