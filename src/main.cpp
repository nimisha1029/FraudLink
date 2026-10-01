#include <iostream>
#include <vector>
#include "Account.h"
#include "DataLoader.h"
#include "TransactionLoader.h"
#include "DeviceLoader.h"
#include "AccountSearch.h"
#include "AccountIndex.h"

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

    AccountSearch searcher;
    AccountIndex indexer;

        string searchId = "A002";

        // Linear search
        int linearResult = searcher.linearSearch(accounts, searchId);

        // Hash-based search
        indexer.buildIndex(accounts);
        int hashResult = indexer.findAccount(searchId);

        if (linearResult != -1) {
            cout << "Linear search found: "
                << accounts[linearResult].name << endl;
        } else {
            cout << "Linear search: Account not found" << endl;
        }

        if (hashResult != -1) {
            cout << "Hash search found: "
                << accounts[hashResult].name << endl;
        } else {
            cout << "Hash search: Account not found" << endl;
        }
    return 0;
}