#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <string>

using namespace std;

class DataGenerator {
public:

    // Generate accounts.csv
    void generateAccounts(string filename, int numberOfAccounts);

    // Generate transactions.csv
    void generateTransactions(string filename,
                             int numberOfTransactions,
                             int numberOfAccounts);

    // Generate devices.csv
    void generateDevices(string filename,
                         int numberOfDevices,
                         int numberOfRecords,
                         int numberOfAccounts);
};

#endif