#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    string id;
    string senderId;
    string receiverId;
    double amount;
    string deviceId;
};

#endif