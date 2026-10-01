#include <iostream>
#include <vector>
#include "Account.h"
#include "DataLoader.h"

using namespace std;

int main() {
    vector<Account> accounts = loadAccounts("data/accounts.csv");

    cout << "FraudLink - Account Records" << endl;

    for (int i = 0; i < accounts.size(); i++) {
        cout << "ID: " << accounts[i].id << endl;
        cout << "Name: " << accounts[i].name << endl;
        cout << "Balance: " << accounts[i].balance << endl;
    }

    cout << "Total accounts loaded: " << accounts.size() << endl;

    return 0;
}