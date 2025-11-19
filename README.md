# AADS Practicals - Advanced Algorithm & Data Structures

A comprehensive collection of algorithm implementations for **B.Sc. (Hons.) Computer Science Semester 5th** of **Delhi University**. This repository contains practical implementations of fundamental algorithms in C++ with detailed explanations, making it ideal for both learning and reference.

## 📚 Table of Contents
- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [How to Compile and Run](#how-to-compile-and-run)
- [Algorithms Implemented](#algorithms-implemented)
  - [1. Randomized Quick Sort](#1-randomized-quick-sort)
  - [2. Randomized Selection](#2-randomized-selection)
  - [3. Kruskal's MST Algorithm](#3-kruskals-mst-algorithm)
  - [4. Bellman-Ford Algorithm](#4-bellman-ford-algorithm)
  - [5. B-Tree](#5-b-tree)
  - [6. KMP Pattern Matching](#6-kmp-pattern-matching)
- [Key Concepts Explained](#key-concepts-explained)
  - [Minimum Spanning Tree (MST)](#minimum-spanning-tree-mst)
  - [Shortest Path Problems](#shortest-path-problems)
  - [Pattern Matching](#pattern-matching)
- [Complexity Analysis Summary](#complexity-analysis-summary)

---

## Overview

This repository contains practical implementations of six fundamental algorithms that are essential in computer science. Each implementation is written in C++ with no external dependencies required, making them easy to compile and run on any system with a C++ compiler.

## Prerequisites

- C++ Compiler (g++, clang++, or any C++11 compatible compiler)
- Basic understanding of C++ syntax
- Familiarity with basic data structures (arrays, trees, graphs)

## How to Compile and Run

All programs can be compiled using a standard C++ compiler. Here's the general syntax:

```bash
g++ -std=c++11 filename.cpp -o output
./output
```

**Example:**
```bash
g++ -std=c++11 random_quicksort.cpp -o quicksort
./quicksort
```

---

## Algorithms Implemented

### 1. Randomized Quick Sort
**File:** `random_quicksort.cpp`

#### What is it?
Randomized Quick Sort is a sorting algorithm that uses a divide-and-conquer approach with randomized pivot selection to sort an array efficiently.

#### How it works:
1. **Randomized Pivot Selection:** Instead of always choosing the first, last, or middle element as pivot, a random element is selected. This helps avoid worst-case scenarios on already sorted or reverse-sorted arrays.
2. **Partitioning:** The array is partitioned around the pivot such that elements smaller than the pivot are on the left, and larger elements are on the right.
3. **Recursive Sorting:** The algorithm recursively sorts the left and right subarrays.
4. **Comparison Counting:** This implementation tracks the number of comparisons made during sorting.

#### Time Complexity:
- **Best Case:** O(n log n)
- **Average Case:** O(n log n) - Randomization ensures average case performance in most scenarios
- **Worst Case:** O(n²) - Rare due to randomization

#### Space Complexity:
- **O(log n)** - Due to recursive call stack

#### Why Randomization?
Randomization helps avoid worst-case behavior when dealing with already sorted or specially arranged input arrays. It ensures good expected performance regardless of input patterns.

#### Usage:
```bash
g++ -std=c++11 random_quicksort.cpp -o quicksort
./quicksort
```

The program will sort a predefined array and display:
- The sorted array
- Total number of comparisons made

---

### 2. Randomized Selection
**File:** `random_selection.cpp`

#### What is it?
Randomized Selection is an algorithm to find the **ith smallest element** in an unsorted array without fully sorting it. It's based on the QuickSelect algorithm.

#### How it works:
1. **Random Partitioning:** Similar to QuickSort, select a random pivot and partition the array.
2. **Position Check:** After partitioning, check the pivot's position:
   - If it's at the ith position, return it
   - If i is less than pivot position, search in the left subarray
   - If i is greater than pivot position, search in the right subarray
3. **Recursion:** Recursively search only the relevant subarray (unlike QuickSort which sorts both sides)

#### Time Complexity:
- **Best Case:** O(n)
- **Average Case:** O(n) - Much better than sorting the entire array
- **Worst Case:** O(n²) - Rare due to randomization

#### Space Complexity:
- **O(log n)** - Due to recursive calls

#### Real-world Applications:
- Finding median in a dataset
- Finding top K elements
- Order statistics in databases

#### Usage:
```bash
g++ -std=c++11 random_selection.cpp -o selection
./selection
```

---

### 3. Kruskal's MST Algorithm
**File:** `Kruksal.cpp`

#### What is it?
Kruskal's algorithm finds the **Minimum Spanning Tree (MST)** of a weighted, undirected graph. An MST connects all vertices with the minimum total edge weight and no cycles.

#### How it works:
1. **Sort Edges:** Sort all edges by weight in ascending order
2. **Initialize DSU:** Create a Disjoint Set Union (Union-Find) data structure to track connected components
3. **Edge Selection:** For each edge (in sorted order):
   - If adding the edge doesn't create a cycle (vertices are in different components), add it to MST
   - Use Union-Find to efficiently check and merge components
4. **Termination:** Stop when we have V-1 edges (where V is number of vertices)

#### Time Complexity:
- **O(E log E)** or **O(E log V)** where E = edges, V = vertices
  - Sorting edges: O(E log E)
  - Union-Find operations: Nearly O(1) with path compression and union by rank

#### Space Complexity:
- **O(V + E)** - Storing vertices and edges

#### Union-Find (Disjoint Set Union):
This data structure supports two operations:
- **Find:** Determine which set an element belongs to (with path compression)
- **Union:** Merge two sets (with union by rank for efficiency)

#### Usage:
```bash
g++ -std=c++11 Kruksal.cpp -o kruskal
./kruskal
```

**Example Input:**
```
Enter number of vertices and edges: 4 5
Enter each edge (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

---

### 4. Bellman-Ford Algorithm
**File:** `bellman_ford.cpp`

#### What is it?
The Bellman-Ford algorithm finds the **shortest paths** from a source vertex to all other vertices in a weighted graph. Unlike Dijkstra's algorithm, it can handle **negative edge weights** and detect **negative cycles**.

#### How it works:
1. **Initialization:** Set distance to source as 0, all others as infinity
2. **Relaxation:** For V-1 iterations (where V = vertices):
   - For each edge (u, v) with weight w:
     - If distance[u] + w < distance[v], update distance[v]
3. **Negative Cycle Detection:** Run one more iteration:
   - If any distance can still be reduced, a negative cycle exists

#### Time Complexity:
- **O(V × E)** where V = vertices, E = edges

#### Space Complexity:
- **O(V)** - Storing distances for all vertices

#### When to use Bellman-Ford vs. Dijkstra:
- **Bellman-Ford:** Graphs with negative weights, need negative cycle detection
- **Dijkstra:** Graphs with only non-negative weights (faster)

#### Real-world Applications:
- Network routing protocols (distance-vector routing)
- Currency arbitrage detection (negative cycles = profit opportunities)
- Route planning with costs

#### Usage:
```bash
g++ -std=c++11 bellman_ford.cpp -o bellman
./bellman
```

The program includes three test cases demonstrating:
1. Normal graph with positive and negative edges
2. Graph with negative edges but no cycle
3. Graph with negative cycle detection

---

### 5. B-Tree
**File:** `Btree.cpp`

#### What is it?
A B-Tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in **logarithmic time**. It's optimized for systems that read and write large blocks of data.

#### How it works:
1. **Node Structure:** Each node can contain multiple keys (not just one like binary trees)
2. **Properties:**
   - All leaves are at the same level (perfectly balanced)
   - Each node has minimum and maximum number of children
   - Keys within a node are sorted
3. **Minimum Degree (T):** In this implementation, T=3
   - Each node (except root) must have at least T-1 keys
   - Each node can have at most 2T-1 keys

#### Time Complexity:
- **Search:** O(log n)
- **Insertion:** O(log n)
- **Deletion:** O(log n)

#### Space Complexity:
- **O(n)** - Storing all keys

#### Why B-Trees?
- **Database Systems:** B-Trees minimize disk I/O operations
- **File Systems:** Used in many file systems (NTFS, ext4, HFS+)
- **Better than Binary Trees:** Fewer levels mean fewer disk accesses

#### Real-world Applications:
- Database indexing (MySQL, PostgreSQL)
- File system implementations
- Any system requiring efficient disk-based storage

#### Usage:
```bash
g++ -std=c++11 Btree.cpp -o btree
./btree
```

**Note:** This is a basic implementation. Production B-Trees include split, merge, and deletion operations.

---

### 6. KMP Pattern Matching
**File:** `kmp.cpp`

#### What is it?
The **Knuth-Morris-Pratt (KMP)** algorithm is an efficient string matching algorithm that finds all occurrences of a pattern in a text in linear time.

#### How it works:
1. **Preprocessing - LPS Array:** Create a Longest Proper Prefix which is also Suffix array
   - LPS[i] = length of longest proper prefix of pattern[0...i] which is also a suffix
   - This tells us how many characters to skip when a mismatch occurs
2. **Searching:** 
   - Compare pattern with text character by character
   - On mismatch, use LPS array to avoid redundant comparisons
   - Never go back in the text, only adjust pattern position

#### Time Complexity:
- **Preprocessing:** O(m) where m = pattern length
- **Searching:** O(n) where n = text length
- **Overall:** O(n + m)

#### Space Complexity:
- **O(m)** - For storing the LPS array

#### Why KMP is Better than Naive Search:
- **Naive approach:** O(n × m) - checks every position
- **KMP approach:** O(n + m) - never backtracks in text
- Avoids redundant comparisons using information from previous matches

#### Real-world Applications:
- Text editors (find/replace functionality)
- DNA sequence matching in bioinformatics
- Plagiarism detection
- Data mining and log analysis

#### Usage:
```bash
g++ -std=c++11 kmp.cpp -o kmp
./kmp
```

**Example:**
```
Input: 
aba
abababaaba

Output:
Pattern found at idx: 0
Pattern found at idx: 2
Pattern found at idx: 4
Pattern found at idx: 7
```

---

## Key Concepts Explained

### Minimum Spanning Tree (MST)

#### What is a Spanning Tree?
A spanning tree of a graph G is a subgraph that:
- Includes all vertices of G
- Is a tree (connected and acyclic)
- Has exactly V-1 edges (where V = number of vertices)

#### What is a Minimum Spanning Tree?
Among all possible spanning trees of a weighted graph, the MST is the one with the **minimum total edge weight**.

#### Properties of MST:
- **Unique:** If all edge weights are distinct, MST is unique
- **Cycle Property:** For any cycle in the graph, the heaviest edge is not in any MST
- **Cut Property:** For any cut (partition of vertices), the lightest edge crossing the cut is in some MST

#### MST Algorithms:
1. **Kruskal's Algorithm** (implemented here) - Edge-based, uses Union-Find
2. **Prim's Algorithm** - Vertex-based, grows tree from a starting vertex
3. **Borůvka's Algorithm** - Parallel-friendly algorithm

#### Real-world Applications:
- Network design (minimum cost to connect all nodes)
- Circuit design
- Cluster analysis
- Approximation algorithms for NP-hard problems (e.g., Traveling Salesman)

---

### Shortest Path Problems

#### Single-Source Shortest Path:
Finding shortest paths from one source vertex to all other vertices.

**Algorithms:**
- **Dijkstra's Algorithm:** Works with non-negative weights, O((V + E) log V) with priority queue
- **Bellman-Ford Algorithm:** (Implemented here) Handles negative weights, O(V × E)

#### Why Negative Edges Matter:
- Some real-world scenarios have "negative" costs (discounts, incentives)
- Negative cycles create problems (infinite cost reduction)
- Only Bellman-Ford can detect negative cycles

#### All-Pairs Shortest Path:
Finding shortest paths between every pair of vertices.
- **Floyd-Warshall Algorithm:** O(V³), works with negative edges

---

### Pattern Matching

#### String Matching Problem:
Given a text T and pattern P, find all occurrences of P in T.

#### Approaches:
1. **Naive/Brute Force:** O(n × m) - Check every position
2. **KMP Algorithm:** (Implemented here) O(n + m) - Avoid redundant comparisons
3. **Boyer-Moore:** O(n/m) best case - Skip sections of text
4. **Rabin-Karp:** O(n + m) - Uses hashing

#### The LPS Array (KMP's Secret):
The Longest Proper Prefix which is also Suffix array is key to KMP's efficiency.

**Example:** For pattern "ABABC"
```
Pattern: A B A B C
LPS:     0 0 1 2 0
```
- LPS[2] = 1 because "A" is both prefix and suffix of "ABA"
- LPS[3] = 2 because "AB" is both prefix and suffix of "ABAB"

This tells us: when we have a mismatch, we don't start from scratch!

---

## Complexity Analysis Summary

| Algorithm | Time Complexity | Space Complexity | Best For |
|-----------|----------------|------------------|----------|
| Randomized Quick Sort | O(n log n) avg | O(log n) | General-purpose sorting |
| Randomized Selection | O(n) avg | O(log n) | Finding kth element without full sort |
| Kruskal's MST | O(E log E) | O(V + E) | Sparse graphs, edge-based approach |
| Bellman-Ford | O(V × E) | O(V) | Negative edges, cycle detection |
| B-Tree Operations | O(log n) | O(n) | Disk-based storage, databases |
| KMP Pattern Matching | O(n + m) | O(m) | Text searching, no backtracking |

**Legend:**
- n = number of elements/characters
- m = pattern length
- V = number of vertices
- E = number of edges

---

## Additional Resources for Beginners

### Graph Theory Basics:
- **Graph:** Collection of vertices (nodes) and edges (connections)
- **Weighted Graph:** Edges have associated costs/weights
- **Directed vs Undirected:** Edges have direction or bidirectional
- **Cycle:** Path that starts and ends at same vertex
- **Connected Graph:** Path exists between every pair of vertices

### Algorithm Design Paradigms:
- **Divide and Conquer:** Quick Sort, Merge Sort
- **Greedy:** Kruskal's, Dijkstra's (locally optimal choices)
- **Dynamic Programming:** Bellman-Ford (optimal substructure)
- **Randomization:** Randomized Quick Sort, QuickSelect

### Big-O Notation Simplified:
- **O(1):** Constant time - same speed regardless of input size
- **O(log n):** Logarithmic - halves problem each step (binary search)
- **O(n):** Linear - proportional to input size
- **O(n log n):** Log-linear - efficient sorting algorithms
- **O(n²):** Quadratic - nested loops
- **O(2ⁿ):** Exponential - very slow, avoid if possible

---

## Contributing

Feel free to:
- Report bugs or issues
- Suggest improvements
- Add more algorithms
- Improve documentation

## License

This repository is for educational purposes as part of Delhi University B.Sc. (Hons.) Computer Science curriculum.

---

## Author

Created as part of Advanced Algorithm & Data Structures (AADS) practical coursework.

**Happy Coding! 🚀**
