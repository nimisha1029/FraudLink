#include "AccountSearch.h"

int AccountSearch::linearSearch(vector<Account>& accounts, string id) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].id == id) {
            return i;
        }
    }
    return -1;
}