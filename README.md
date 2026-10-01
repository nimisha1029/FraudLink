# FraudLink

**Transaction Network Explorer and Suspicious
Relationship Analyzer**

FraudLink is a C++17 DSA project that explores
relationships between financial accounts, transactions,
and devices using graph algorithms and hash-based
indexing.

## Project Objective

The project demonstrates how fundamental Data
Structures and Algorithms can be used to efficiently
retrieve account records and explore interconnected
transaction networks.

FraudLink uses rule-based pattern analysis to flag
potentially suspicious shared-device clusters for
further investigation. It is an educational prototype,
not an automated fraud detection system.

## Features

- Account lookup using `unordered_map`
- Linear search as a performance baseline
- Graph representation using adjacency lists
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Shared-device cluster detection
- Synthetic transaction dataset
- Search performance comparison

## Technology Stack

- C++17
- Standard Template Library (STL)
- CSV datasets
- Git and GitHub
- Visual Studio Code

## Project Structure

- `data/` - Sample CSV datasets
- `include/` - Header files
- `src/` - C++ source files
- `tests/` - Test cases
- `docs/` - Project documentation

## Team

- Member 1: Data Generation and Searching
- Member 2: Hash Indexing and Graph Construction
- Member 3: Graph Traversal and Pattern Analysis

## Build and Run

Build and execution instructions will be added
once the initial implementation is ready.

## Disclaimer

FraudLink uses synthetic data and educational,
rule-based analysis. A flagged relationship
does not establish that fraud has occurred.
