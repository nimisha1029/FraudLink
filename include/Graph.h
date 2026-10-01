#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Account.h"
#include "Transaction.h"

using namespace std;

// Stores the details of one transaction edge
class TransactionEdge {
public:
    string transactionId;
    string receiverId;
    double amount;
};

class Graph {
private:
    // Sender account -> list of outgoing transaction edges
    unordered_map<string, vector<TransactionEdge>> adjacencyList;

    // Helper function for DFS
    void dfsHelper(string accountId,
                   unordered_map<string, bool>& visited);

public:
    // Build graph using all accounts and transactions
    void buildGraph(vector<Account>& accounts,
                    vector<Transaction>& transactions);

    // Add one transaction to the graph
    void addTransaction(Transaction transaction);

    // Display the adjacency list
    void displayGraph();

    // Graph traversal
    void BFS(string startId);
    void DFS(string startId);
};

#endif