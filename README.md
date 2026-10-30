# FraudLink

*Transaction Network Explorer and Suspicious Relationship Analyzer*

FraudLink is a C++17 Data Structures and Algorithms (DSA) project that explores relationships between financial accounts, transactions, and devices using efficient data structures and graph algorithms.

It demonstrates how account records can be retrieved efficiently, how financial transactions can be represented as interconnected networks, and how shared-device relationships can be analyzed to identify potentially suspicious patterns.

FraudLink uses synthetic data and rule-based analysis. It is an educational prototype and does not automatically determine whether fraud has occurred.

## Project Objectives

- Implement efficient account retrieval using linear search and hash-based indexing.
- Represent financial transactions as a directed graph using adjacency lists.
- Explore transaction networks using BFS and DFS.
- Identify devices shared by multiple accounts using hash-based grouping.
- Compare the performance of different searching and graph operations.
- Demonstrate the practical applications of fundamental DSA concepts.

## Features

### 1. Account Search
- Linear search to retrieve an account using its ID.
- Hash-based account lookup using unordered_map.
- Comparison of both searching approaches.

### 2. Transaction Network Representation
- Represents accounts as graph vertices.
- Represents financial transactions as directed edges.
- Uses an adjacency-list representation to store transaction relationships.
- Stores transaction details such as transaction ID, receiver ID, and amount.

### 3. Graph Traversal
- *Breadth-First Search (BFS):* Explores reachable accounts level by level using a queue.
- *Depth-First Search (DFS):* Explores connected transaction paths using recursion.

### 4. Shared-Device Analysis
- Groups accounts according to the devices they use.
- Counts the number of accounts associated with each device.
- Flags devices shared by more than a specified threshold of accounts for further investigation.

### 5. Performance Analysis
- Compares linear search and hash-based lookup.
- Measures graph construction and traversal execution times.
- Evaluates algorithm performance across different dataset sizes.

## Technology Stack

- *Language:* C++17
- *Data Structures:* Vectors, queues, stacks (where applicable), hash maps and adjacency lists
- *Algorithms:* Linear Search, Hash-based Lookup, BFS and DFS
- *Libraries:* C++ Standard Template Library (STL)
- *Data Storage:* CSV files containing synthetic records
- *Development Tools:* Visual Studio Code, Git and GitHub

## Dataset

FraudLink uses synthetically generated CSV datasets.

| Dataset | Description |
|---|---|
| accounts.csv | Account IDs, account names and balances |
| transactions.csv | Transaction IDs, sender accounts, receiver accounts and transaction amounts |
| devices.csv | Device IDs, device types and associated account IDs |

*Target dataset size:*

- 1,000 accounts
- 10,000 transactions
- 1,500 device-account association records
- 400 unique devices

The dataset includes intentionally shared devices to test the shared-device analysis functionality.

## Project Structure

text <br>
FraudLink/ <br>
│<br>
├── data/<br>
│   ├── accounts.csv<br>
│   ├── transactions.csv<br>
│   └── devices.csv<br>
│<br>
├── include/<br>
│   ├── Account.h<br>
│   ├── Transaction.h<br>
│   ├── Device.h<br>
│   ├── DataLoader.h<br>
│   ├── TransactionLoader.h<br>
│   ├── DeviceLoader.h<br>
│   ├── AccountSearch.h<br>
│   ├── AccountIndex.h<br>
│   ├── Graph.h<br><br>
│   ├── Analyzer.h<br><br>
│   └── DataGenerator.h<br>
│<br>
├── src/<br>
│   ├── DataLoader.cpp<br>
│   ├── TransactionLoader.cpp<br>
│   ├── DeviceLoader.cpp<br>
│   ├── AccountSearch.cpp<br>
│   ├── AccountIndex.cpp<br>
│   ├── Graph.cpp<br>
│   ├── Analyzer.cpp<br>
│   └── DataGenerator.cpp<br>
│<br>
├── main.cpp<br>
├── generate_data.cpp<br>
└── README.md<br>

## Build and Run

### 1. Generate the synthetic datasets

Compile the data generator:

bash
g++ -std=c++17 -Iinclude generate_data.cpp src/DataGenerator.cpp -o generate_data


Run:

bash
./generate_data


### 2. Compile FraudLink

bash
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o fraudlink


### 3. Run the application

bash
./fraudlink


## Application Menu

FraudLink provides a menu-driven command-line interface:

1. Search Account
2. Display Transaction Graph
3. BFS Traversal
4. DFS Traversal
5. Shared Device Analysis
6. Exit

## Team

- *Member 1:* Data Generation, CSV Loading and Linear Search
- *Member 2:* Hash-based Account Indexing and Graph Construction
- *Member 3:* BFS, DFS, Shared-Device Analysis and Performance Testing

## Future Improvements

- Expand dataset sizes for further scalability testing.
- Improve transaction network visualization.
- Introduce additional rule-based relationship analysis.
- Extend performance evaluation to larger datasets.

## Disclaimer

FraudLink uses synthetic data and educational, rule-based analysis. A shared device or flagged relationship does not establish that fraud has occurred. Results are intended to identify relationships for further investigation, not to make automated financial decisions.
