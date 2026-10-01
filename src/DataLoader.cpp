#include <iostream>
#include <fstream>
#include <sstream>
#include "DataLoader.h"

using namespace std;

vector<Account> DataLoader::loadAccounts(string filename) {
    vector<Account> accounts;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return accounts;
    }

    string line;

    // Skip the header row
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, balanceStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, balanceStr, ',');

        if (id.empty() || name.empty() || balanceStr.empty()) {
            continue;
        }

        Account a;
        a.id = id;
        a.name = name;
        a.balance = stod(balanceStr);

        accounts.push_back(a);
    }

    file.close();

    return accounts;
}