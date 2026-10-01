#include "AccountIndex.h"

void AccountIndex::buildIndex(vector<Account>& accounts) {
    accountMap.clear();

    for (int i = 0; i < accounts.size(); i++) {
        accountMap[accounts[i].id] = i;
    }
}

int AccountIndex::findAccount(string id) {
    if (accountMap.find(id) != accountMap.end()) {
        return accountMap[id];
    }

    return -1;
}