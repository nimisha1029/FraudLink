#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Device.h"

using namespace std;

class Analyzer {
public:
    void findSharedDevices(vector<Device>& devices, int threshold);
};

#endif