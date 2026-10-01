#ifndef ACCOUNTSEARCH_H
#define ACCOUNTSEARCH_H

#include <vector>
#include <string>
#include "Account.h"
using namespace std;

class AccountSearch {
public:
    int linearSearch(vector<Account>& accounts, string id);
};

#endif