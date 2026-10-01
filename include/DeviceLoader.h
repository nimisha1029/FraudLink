#ifndef DEVICELOADER_H
#define DEVICELOADER_H

#include <vector>
#include <string>
#include "Device.h"
using namespace std;

class DeviceLoader {
public:
    vector<Device> loadDevices(string filename);
};

#endif