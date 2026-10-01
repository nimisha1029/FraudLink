#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "Account.h"

using namespace std;

vector<Account> loadAccounts(string filename);

#endif