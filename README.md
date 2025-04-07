# Graph Project 1 - README

## Student Info

- **Name:** shir bismuth  
- **Email:** shirbismoth@gmail.com

---

## Project Overview

This project builds an undirected weighted graph using an adjacency list and includes several algorithms for graph traversal and analysis. All data structures and algorithms are implemented from scratch without relying on the C++ STL, as required.

---

## Implemented Classes

### 1. `Graph`

- Represents an undirected graph using an adjacency list.
- Main features:
  - `addEdge(from, to, weight)` - Adds an undirected edge between two vertices.
  - `removeEdge(from, to)` - Removes an undirected edge between two vertices.
  - `print_graph()` - Prints the graph's adjacency list.
  - Input validation and exception handling are included to prevent invalid operations.

### 2. `Algorithms`

This class includes the following graph algorithms:

- **BFS (Breadth-First Search)** – Constructs a BFS tree starting from a specified vertex.
- **DFS (Depth-First Search)** – Constructs a DFS tree starting from a given vertex.
- **Dijkstra** – Computes the shortest paths from a source vertex (only for graphs with non-negative weights).
- **Prim** – Builds a minimum spanning tree (checks graph connectivity and assumes non-negative edge weights).
- **Kruskal** – Builds a minimum spanning tree using union-find (allows for negative edge weights).

All algorithms throw exceptions for invalid input or unsupported graph configurations.

### 3. `Queue`

- Implements a circular queue using a raw array.
- Core functions:
  - `enqueue(value)` – Adds a value to the queue.
  - `dequeue()` – Removes a value from the front of the queue.
  - `isEmpty()` – Checks if the queue is empty.

### 4. `MinHeap`

- A custom priority queue used in Dijkstra’s and Prim’s algorithms.
- Maintains vertex-distance pairs for efficient access to the smallest distance.
- Core functions:
  - `insert(v, dist)` – Inserts a vertex with a given distance.
  - `extractMin()` – Extracts the vertex with the minimum distance.
  - `decreaseKey(v, dist)` – Decreases the key (distance) of a vertex.
  - `contains(v)` – Checks if a vertex exists in the heap.
  - `getDist(v)` – Returns the distance associated with a vertex.

### 5. `UnionFind`

- Supports Kruskal's algorithm for minimum spanning tree.
- Efficient union and find operations with path compression and union by rank.

---

## Input Validation and Exceptions

- All algorithms validate inputs to ensure proper functioning:
  - Checking for invalid start vertices.
  - Ensuring the graph is not empty.
  - Preventing the use of negative edge weights where not allowed.
- Descriptive exceptions are thrown for invalid operations.

---

## Memory Management

- Manual dynamic memory management (`new` / `delete`) is used throughout the code.
- The project has been verified with `valgrind` to ensure no memory leaks.

---

## Compilation and Running

- Use the provided `Makefile` to manage the compilation and execution of the project:
  - `make Main` – Compiles the main application and runs the demo.
  - `make test` – Compiles and runs unit tests.
  - `make valgrind` – Runs the program with `valgrind` to check for memory leaks.
  - `make clean` – Cleans up all generated files.

---

## Additional Notes

- Each class is implemented in its own `.cpp` and `.hpp` files for clear separation of concerns.
- Unit tests are implemented using `assert` to ensure the correctness of all algorithms and data structures.
- This project follows best practices for C++ programming, with a focus on efficiency and clarity.
- The tests are divided into separate files, and the test_all file consolidates them all.

