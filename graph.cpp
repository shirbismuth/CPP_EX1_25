#include <iostream>
#include <stdexcept> 
#include "graph.hpp"

namespace graph {

    /**
     * @class Graph
     * @brief Represents an undirected weighted graph using an adjacency list.
     * 
     * The Graph class provides methods to add and remove edges, print the graph,
     * and access its vertices and adjacency list.
     */

    /**
     * @brief Constructs a graph with a specified number of vertices.
     * @param vertices The number of vertices in the graph.
     * @throws std::invalid_argument if the number of vertices is not positive.
     */
    Graph::Graph(int vertices) : vertices(vertices) {
        if (vertices <= 0) {
            throw std::invalid_argument("Number of vertices must be positive.");
        }
        list = new Node*[vertices];
        for (int i = 0; i < vertices; ++i) {
            list[i] = nullptr;
        }
    }

    /**
     * @brief Destructor to clean up dynamically allocated memory.
     */
    Graph::~Graph() {
        for (int i = 0; i < vertices; ++i) {
            Node* current = list[i];
            while (current) {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] list;
    }

    /**
     * @brief Adds an edge between two vertices with a specified weight.
     * @param src The source vertex.
     * @param des The destination vertex.
     * @param weight The weight of the edge.
     * @throws std::out_of_range if the source or destination vertex index is invalid.
     */
    void Graph::addEdge(int src, int des, int weight) {
        if (src < 0 || src >= vertices || des < 0 || des >= vertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        list[src] = new Node(des, weight, list[src]);
        list[des] = new Node(src, weight, list[des]);
    }

    /**
     * @brief Removes an edge between two vertices.
     * @param src The source vertex.
     * @param des The destination vertex.
     * @throws std::out_of_range if the source or destination vertex index is invalid.
     * @throws std::runtime_error if the edge does not exist.
     */
    void Graph::removeEdge(int src, int des) {
        if (src < 0 || src >= vertices || des < 0 || des >= vertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        Node** curr = &list[src];
        bool found = false;
        while (*curr) {
            if ((*curr)->vertex == des) {
                Node* toDelete = *curr;
                *curr = (*curr)->next;
                delete toDelete;
                found = true;
                break;
            }
            curr = &((*curr)->next);
        }

        curr = &list[des];
        while (*curr) {
            if ((*curr)->vertex == src) {
                Node* toDelete = *curr;
                *curr = (*curr)->next;
                delete toDelete;
                found = true;
                break;
            }
            curr = &((*curr)->next);
        }

        if (!found) {
            throw std::runtime_error("Edge does not exist");
        }
    }

    /**
     * @brief Prints the adjacency list representation of the graph.
     */
    void Graph::print_graph() const {
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ":";
            Node* current = list[i];
            while (current) {
                std::cout << " -> (" << current->vertex << ", w=" << current->weight << ")";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    /**
     * @brief Gets the number of vertices in the graph.
     * @return The number of vertices.
     */
    int Graph::getVertices() const {
        return vertices;
    }

    /**
     * @brief Gets the adjacency list of the graph.
     * @return A pointer to the adjacency list.
     */
    Node** Graph::getAdjList() const {
        return list;
    }

}
