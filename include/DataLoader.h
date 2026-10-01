#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "Account.h"

class DataLoader {
public:
    vector<Account> loadAccounts(string filename);
};

#endif