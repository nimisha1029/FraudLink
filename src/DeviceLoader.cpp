#include <iostream>
#include <fstream>
#include <sstream>
#include "DeviceLoader.h"

using namespace std;

vector<Device> DeviceLoader::loadDevices(string filename) {
    vector<Device> devices;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return devices;
    }

    string line;
    getline(file, line); // Skip the header row

    while (getline(file, line)) {
        stringstream ss(line);
        Device d;

        getline(ss, d.id, ',');
        getline(ss, d.type, ',');
        getline(ss, d.accountId, ',');

        devices.push_back(d);
    }

    file.close();
    return devices;
}