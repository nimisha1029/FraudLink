#include <iostream>
#include <fstream>
#include <sstream>
#include "TransactionLoader.h"

using namespace std;

vector<Transaction> TransactionLoader::loadTransactions(string filename) {
    vector<Transaction> transactions;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return transactions;
    }

    string line;
    getline(file, line); // Skip the header row

    while (getline(file, line)) {
        stringstream ss(line);
        string amountText;
        Transaction t;

        getline(ss, t.id, ',');
        getline(ss, t.senderId, ',');
        getline(ss, t.receiverId, ',');
        getline(ss, amountText, ',');
        getline(ss, t.deviceId, ',');

        t.amount = stod(amountText);
        transactions.push_back(t);
    }

    file.close();
    return transactions;
}