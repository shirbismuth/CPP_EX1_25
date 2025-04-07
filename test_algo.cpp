#include "graph.hpp"
#include "min_heap.hpp"
#include "queue.hpp"
#include "union_find.hpp"
#include "algorithms.hpp"
#include <cassert>
#include <iostream>

// Test function for BFS algorithm.
void testBFS() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    try {
        graph::Algorithms::BFS(g, 0);  
    } catch (const std::exception& e) {
        std::cerr << "BFS test failed: " << e.what() << std::endl;
    }
}

// Test function for DFS algorithm.
void testDFS() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    try {
        graph::Algorithms::DFS(g, 0);  
    } catch (const std::exception& e) {
        std::cerr << "DFS test failed: " << e.what() << std::endl;
    }
}

// Test function for Dijkstra's algorithm.
void testDijkstra() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    try {
        graph::Algorithms::Dijkstra(g, 0);  
    } catch (const std::exception& e) {
        std::cerr << "Dijkstra test failed: " << e.what() << std::endl;
    }
}

// Test function for Prim's algorithm.
void testPrim() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    try {
        graph::Algorithms::Prim(g);  
    } catch (const std::exception& e) {
        std::cerr << "Prim test failed: " << e.what() << std::endl;
    }
}

// Test function for Kruskal's algorithm.
void testKruskal() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    try {
        graph::Algorithms::Kruskal(g);  
    } catch (const std::exception& e) {
        std::cerr << "Kruskal test failed: " << e.what() << std::endl;
    }
}


