#ifndef ACCOUNTINDEX_H
#define ACCOUNTINDEX_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Account.h"
using namespace std;

class AccountIndex {
private:
    unordered_map<string, int> accountMap;

public:
    void buildIndex(vector<Account>& accounts);
    int findAccount(string id);
};

#endif