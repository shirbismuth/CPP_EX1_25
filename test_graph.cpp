#include "graph.hpp"
#include <cassert>
#include <iostream>

// Test adding an edge to the graph.
void testGraphAddEdge() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);  
    assert(g.getAdjList()[0] != nullptr);  
    assert(g.getAdjList()[1] != nullptr);  
    
}

// Test removing an edge from the graph.
void testGraphRemoveEdge() {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);  
    g.removeEdge(0, 1);  
    assert(g.getAdjList()[0] == nullptr);  
    assert(g.getAdjList()[1] == nullptr);  
   
}

// Test adding an edge with invalid vertex indices.
void testGraphAddEdgeInvalidIndex() {
    graph::Graph g(5);
    try {
        g.addEdge(-1, 5, 10);  
        assert(false); 
    } catch (const std::out_of_range& e) {
        std::cout << "testGraphAddEdgeInvalidIndex passed! " << e.what() << std::endl;
    }
}

// Test removing a non-existent edge from the graph.
void testGraphRemoveEdgeNotFound() {
    graph::Graph g(5);
    try {
        g.removeEdge(0, 1);  
        assert(false);  
    } catch (const std::runtime_error& e) {
        std::cout << "testGraphRemoveEdgeNotFound passed! " << e.what() << std::endl;
    }

}
