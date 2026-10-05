#include "Analyzer.h"

using namespace std;

void Analyzer::findSharedDevices(vector<Device>& devices, int threshold) {

    unordered_map<string, vector<string>> deviceAccounts;

    // Build device -> accounts mapping
    for (int i = 0; i < devices.size(); i++) {

        string deviceId = devices[i].id;
        string accountId = devices[i].accountId;

        deviceAccounts[deviceId].push_back(accountId);
    }

    cout << "\nShared Device Analysis:\n";

    // Check each device
    for (auto entry : deviceAccounts) {

        string deviceId = entry.first;
        vector<string> accounts = entry.second;

        cout << "Device: " << deviceId << endl;

        cout << "Accounts using it: ";

        for (int i = 0; i < accounts.size(); i++) {
            cout << accounts[i] << " ";
        }

        cout << endl;

        cout << "Number of accounts: "
             << accounts.size() << endl;

        if (accounts.size() > threshold) {
            cout << "Status: FLAGGED - Shared by too many accounts"
                 << endl;
        }
        else {
            cout << "Status: Normal" << endl;
        }

        cout << endl;
    }
}