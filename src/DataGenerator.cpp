#include "DataGenerator.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

// Create IDs like A001, T001, D001
string makeId(string prefix, int number) {
    stringstream ss;

    ss << prefix << setfill('0') << setw(3) << number;

    return ss.str();
}


// Generate accounts.csv
void DataGenerator::generateAccounts(string filename,
                                     int numberOfAccounts) {

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error creating " << filename << endl;
        return;
    }

    // Seed random number generator
    srand(time(0));

    file << "account_id,name,balance\n";

    for (int i = 1; i <= numberOfAccounts; i++) {

        string accountId = makeId("A", i);

        string name = "Account" + to_string(i);

        double balance = 1000 + rand() % 19001;

        file << accountId << ","
             << name << ","
             << balance << "\n";
    }

    file.close();

    cout << numberOfAccounts
         << " accounts generated successfully.\n";
}


// Generate transactions.csv
void DataGenerator::generateTransactions(string filename,
                                         int numberOfTransactions,
                                         int numberOfAccounts) {

    if (numberOfAccounts < 2) {
        cout << "At least 2 accounts are required.\n";
        return;
    }

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error creating " << filename << endl;
        return;
    }

    file << "transaction_id,sender_id,receiver_id,amount\n";

    for (int i = 1; i <= numberOfTransactions; i++) {

        string transactionId = makeId("T", i);

        int senderNumber =
            1 + rand() % numberOfAccounts;

        int receiverNumber =
            1 + rand() % numberOfAccounts;

        // Sender and receiver must be different
        while (senderNumber == receiverNumber) {
            receiverNumber =
                1 + rand() % numberOfAccounts;
        }

        string senderId = makeId("A", senderNumber);

        string receiverId = makeId("A", receiverNumber);

        double amount = 100 + rand() % 9901;

        file << transactionId << ","
             << senderId << ","
             << receiverId << ","
             << amount << "\n";
    }

    file.close();

    cout << numberOfTransactions
         << " transactions generated successfully.\n";
}


// Generate devices.csv
void DataGenerator::generateDevices(string filename,
                                    int numberOfDevices,
                                    int numberOfRecords,
                                    int numberOfAccounts) {

    // We need at least 20 shared devices and 10 accounts per device
    if (numberOfDevices < 21 ||
        numberOfRecords < 200 ||
        numberOfAccounts < 10) {

        cout << "Invalid device generation settings.\n";
        return;
    }

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error creating " << filename << endl;
        return;
    }

    file << "id,type,account_id\n";

    // First 20 devices will be shared by 10 accounts each.
    // This creates 200 device-account records.

    for (int i = 1; i <= 20; i++) {

        string deviceId = makeId("D", i);

        string deviceType;

        if (i % 3 == 0) {
            deviceType = "mobile";
        }
        else if (i % 3 == 1) {
            deviceType = "laptop";
        }
        else {
            deviceType = "tablet";
        }

        for (int j = 1; j <= 10; j++) {

            int accountNumber = ((i - 1) * 10 + j);

            string accountId = makeId("A", accountNumber);

            file << deviceId << ","
                 << deviceType << ","
                 << accountId << "\n";
        }
    }

    // Remaining records are distributed among
    // the remaining devices.

    int remainingRecords = numberOfRecords - 200;

    int remainingDevices = numberOfDevices - 20;

    for (int i = 0; i < remainingRecords; i++) {

        int deviceNumber =
            21 + (i % remainingDevices);

        int accountNumber =
            1 + ((i * 37) % numberOfAccounts);

        string deviceId = makeId("D", deviceNumber);

        string accountId = makeId("A", accountNumber);

        string deviceType;

        if (deviceNumber % 3 == 0) {
            deviceType = "mobile";
        }
        else if (deviceNumber % 3 == 1) {
            deviceType = "laptop";
        }
        else {
            deviceType = "tablet";
        }

        file << deviceId << ","
             << deviceType << ","
             << accountId << "\n";
    }

    file.close();

    cout << numberOfRecords
         << " device records generated successfully.\n";
}