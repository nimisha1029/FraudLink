#ifndef TRANSACTIONLOADER_H
#define TRANSACTIONLOADER_H

#include <vector>
#include <string>
#include "Transaction.h"
using namespace std;

class TransactionLoader {
public:
    vector<Transaction> loadTransactions(string filename);
};

#endif