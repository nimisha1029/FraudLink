#include <iostream>
#include <vector>
#include "DataLoader.h"
#include "TransactionLoader.h"
#include "DeviceLoader.h"

using namespace std;

int main() {
    DataLoader accountLoader;
    TransactionLoader transactionLoader;
    DeviceLoader deviceLoader;

    vector<Account> accounts =
        accountLoader.loadAccounts("data/accounts.csv");

    vector<Transaction> transactions =
        transactionLoader.loadTransactions("data/transactions.csv");

    vector<Device> devices =
        deviceLoader.loadDevices("data/devices.csv");

    cout << "Accounts loaded: " << accounts.size() << endl;
    cout << "Transactions loaded: " << transactions.size() << endl;
    cout << "Devices loaded: " << devices.size() << endl;

    return 0;
}