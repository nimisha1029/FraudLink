#include "Graph.h"
#include <queue>

using namespace std;

// Build the graph using accounts and transactions
void Graph::buildGraph(vector<Account>& accounts,
                       vector<Transaction>& transactions) {
    adjacencyList.clear();

    // Add every account as a vertex
    for (int i = 0; i < accounts.size(); i++) {
        adjacencyList[accounts[i].id];
    }

    // Add every transaction as a directed edge
    for (int i = 0; i < transactions.size(); i++) {
        addTransaction(transactions[i]);
    }
}

// Add one transaction to the graph
void Graph::addTransaction(Transaction transaction) {
    TransactionEdge edge;

    edge.transactionId = transaction.id;
    edge.receiverId = transaction.receiverId;
    edge.amount = transaction.amount;

    // Add the edge under the sender's account
    adjacencyList[transaction.senderId].push_back(edge);

    // Ensure the receiver exists as a vertex
    adjacencyList[transaction.receiverId];
}

// Display the adjacency list with transaction details
void Graph::displayGraph() {
    for (auto entry : adjacencyList) {
        cout << "Account: " << entry.first << endl;

        for (int i = 0; i < entry.second.size(); i++) {
            cout << "  -> " << entry.second[i].receiverId
                 << " | Transaction: "
                 << entry.second[i].transactionId
                 << " | Amount: "
                 << entry.second[i].amount << endl;
        }

        cout << endl;
    }
}

// Breadth-First Search
void Graph::BFS(string startId) {
    if (adjacencyList.find(startId) == adjacencyList.end()) {
        cout << "Account not found in graph." << endl;
        return;
    }

    unordered_map<string, bool> visited;
    queue<string> q;

    visited[startId] = true;
    q.push(startId);

    cout << "BFS: ";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        cout << current << " ";

        // Visit all outgoing neighbours
        for (int i = 0; i < adjacencyList[current].size(); i++) {
            string neighbour = adjacencyList[current][i].receiverId;

            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

// DFS helper function
void Graph::dfsHelper(string accountId,
                      unordered_map<string, bool>& visited) {
    visited[accountId] = true;
    cout << accountId << " ";

    // Visit all outgoing neighbours
    for (int i = 0; i < adjacencyList[accountId].size(); i++) {
        string neighbour = adjacencyList[accountId][i].receiverId;

        if (!visited[neighbour]) {
            dfsHelper(neighbour, visited);
        }
    }
}

// Depth-First Search
void Graph::DFS(string startId) {
    if (adjacencyList.find(startId) == adjacencyList.end()) {
        cout << "Account not found in graph." << endl;
        return;
    }

    unordered_map<string, bool> visited;

    cout << "DFS: ";
    dfsHelper(startId, visited);
    cout << endl;
}