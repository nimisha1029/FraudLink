#include <iostream>
#include <vector>
#include "Account.h"
#include "DataLoader.h"
#include "TransactionLoader.h"
#include "DeviceLoader.h"
#include "AccountSearch.h"
#include "AccountIndex.h"
#include "Graph.h"
#include "Analyzer.h"

using namespace std;

int main() {

    // load data 

    DataLoader accountLoader;
    TransactionLoader transactionLoader;
    DeviceLoader deviceLoader;

    vector<Account> accounts =
        accountLoader.loadAccounts("data/accounts.csv");

    vector<Transaction> transactions =
        transactionLoader.loadTransactions("data/transactions.csv");

    vector<Device> devices =
        deviceLoader.loadDevices("data/devices.csv");

    // creating objects for linear search , hash indexing, graph representation and analyzer
    AccountSearch searcher;
    AccountIndex indexer;
    Graph graph;
    Analyzer analyzer;

    indexer.buildIndex(accounts);
    graph.buildGraph(accounts, transactions);

    // Main menu
    while (true) {

        cout << "\nWELCOME TO FRAUDLINK \n";
        cout << "BE SAFE FROM FRAUDS \n";

        cout << "1. Search Account\n";
        cout << "2. Display Transaction Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Shared Device Analysis\n";
        cout << "6. Exit\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        // Option 1: Search Account
            if (choice == 1) {
            string searchId;
            cout << "Enter account ID: ";
            cin >> searchId;

            int linearResult =searcher.linearSearch(accounts, searchId);
            int hashResult =indexer.findAccount(searchId);

            if (linearResult != -1) {
                cout << "Linear search found: "
                     << accounts[linearResult].name << endl;
            }
            else {
                cout << "Linear search: Account not found"
                     << endl;
            }
            if (hashResult != -1) {
                cout << "Hash search found: "
                     << accounts[hashResult].name << endl;
            }
            else {
                cout << "Hash search: Account not found"
                     << endl;
            }
        }

        // Option 2: Display Graph
        else if (choice == 2) {
            cout << "\nTransaction Graph:\n";
            graph.displayGraph();
        }
            
        // Option 3: BFS
        else if (choice == 3) {
            string startId;
            cout << "Enter starting account ID: ";
            cin >> startId;
            graph.BFS(startId);
        }

        // Option 4: DFS
        else if (choice == 4) {
            string startId;
            cout << "Enter starting account ID: ";
            cin >> startId;
            graph.DFS(startId);
        }
            
        // Option 5: Shared Device
        else if (choice == 5) {
            int threshold;
            cout << "Enter shared-device threshold: ";
            cin >> threshold;
            analyzer.findSharedDevices(devices, threshold);
        }

        // Option 6: Exit
        else if (choice == 6) {
            cout << "Exiting FraudLink..." << endl;
            break;
        }
            
        // Invalid choice
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0 ; 
}


//     cout << "Accounts loaded: " << accounts.size() << endl;
//     cout << "Transactions loaded: " << transactions.size() << endl;
//     cout << "Devices loaded: " << devices.size() << endl;

//     AccountSearch searcher;
//     AccountIndex indexer;

//         string searchId = "A002";

//         // Linear search
//         int linearResult = searcher.linearSearch(accounts, searchId);

//         // Hash-based search
//         indexer.buildIndex(accounts);
//         int hashResult = indexer.findAccount(searchId);

//         if (linearResult != -1) {
//             cout << "Linear search found: "
//                 << accounts[linearResult].name << endl;
//         } else {
//             cout << "Linear search: Account not found" << endl;
//         }

//         if (hashResult != -1) {
//             cout << "Hash search found: "
//                 << accounts[hashResult].name << endl;
//         } else {
//             cout << "Hash search: Account not found" << endl;
//         }
//     Graph graph;

//     // Build the graph
//     graph.buildGraph(accounts, transactions);

//     // Display graph with transaction details
//     cout << "\nTransaction Graph:\n";
//     graph.displayGraph();

//     // Perform BFS
//     cout << "\n";
//     graph.BFS("A001");

//     // Perform DFS
//     cout << "\n";
//     graph.DFS("A001");
//     cout << "\nDFS finished!" << endl;

//     cout << "Starting analyzer..." << endl;

//     Analyzer analyzer;

//     analyzer.findSharedDevices(devices, 2);

//     cout << "Analyzer finished." << endl;

//     return 0;
// }
