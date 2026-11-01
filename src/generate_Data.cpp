#include <iostream>
#include "DataGenerator.h"

using namespace std;

int main() {

    DataGenerator generator;

    // Generate 1000 accounts
    generator.generateAccounts(
        "data/accounts.csv",
        1000
    );

    // Generate 10000 transactions
    generator.generateTransactions(
        "data/transactions.csv",
        10000,
        1000
    );

    // Generate exactly 1500 device records
    // using exactly 400 unique devices
    generator.generateDevices(
        "data/devices.csv",
        400,
        1500,
        1000
    );

    cout << "\nAll datasets generated!\n";

    return 0;
}