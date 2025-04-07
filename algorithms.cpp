#include "algorithms.hpp" 
#include "graph.hpp"
#include "queue.hpp"
#include "min_heap.hpp"
#include "union_find.hpp"
#include <iostream>
#include <cstdint> 


namespace graph {

    /**
     * Performs Breadth-First Search (BFS) on the given graph starting from the specified vertex.
     * 
     * @param g The graph to perform BFS on.
     * @param start The starting vertex for BFS.
     * @throws std::out_of_range If the start vertex is invalid.
     */
    void Algorithms::BFS(const Graph& g, int start) {
        if (start < 0 || start >= g.getVertices()) {
            throw std::out_of_range("Invalid start vertex for BFS.");
        }
        bool* visited = new bool[g.getVertices()]();
        Queue q(g.getVertices());

        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int current = q.dequeue();
            std::cout << current << " ";

            Node* temp = g.getAdjList()[current];
            while (temp) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.enqueue(temp->vertex);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        std::cout << std::endl;
    }

    /**
     * Performs Depth-First Search (DFS) on the given graph starting from the specified vertex.
     * 
     * Note: This implementation uses an iterative approach with a queue to avoid deep recursion.
     * 
     * @param g The graph to perform DFS on.
     * @param start The starting vertex for DFS.
     * @throws std::out_of_range If the start vertex is invalid.
     */
    void Algorithms::DFS(const Graph& g, int start) {
        if (start < 0 || start >= g.getVertices()) {
            throw std::out_of_range("Invalid start vertex for DFS.");
        }
    
        bool* visited = new bool[g.getVertices()]();
        Queue q(g.getVertices());  // השתמשתי בתור פשוט כדי למנוע רקורסיה עמוקה
    
        q.enqueue(start);
        visited[start] = true;
    
        while (!q.isEmpty()) {
            int current = q.dequeue();
            std::cout << current << " ";
    
            Node* temp = g.getAdjList()[current];
            while (temp) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.enqueue(temp->vertex);
                }
                temp = temp->next;
            }
        }
    
        delete[] visited;
        std::cout << std::endl;
    }
    

    /**
     * Implements Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices.
     * 
     * @param g The graph to perform Dijkstra's algorithm on.
     * @param src The source vertex.
     * @throws std::out_of_range If the source vertex is invalid.
     */
    void Algorithms::Dijkstra(const Graph& g, int src) {
        if (src < 0 || src >= g.getVertices()) {
            throw std::out_of_range("Invalid source vertex for Dijkstra.");
        }
        int V = g.getVertices();
        int* dist = new int[V];
        for (int i = 0; i < V; ++i) dist[i] = INT32_MAX;
        dist[src] = 0;

        MinHeap heap(V);
        heap.insert(src, 0);

        while (!heap.isEmpty()) {
            int u = heap.extractMin();

            Node* temp = g.getAdjList()[u];
            while (temp) {
                int v = temp->vertex;
                int weight = temp->weight;
                if (dist[u] != INT32_MAX && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    if (heap.contains(v))
                        heap.decreaseKey(v, dist[v]);
                    else
                        heap.insert(v, dist[v]);
                }
                temp = temp->next;
            }
        }

        for (int i = 0; i < V; ++i)
            std::cout << "Distance from " << src << " to " << i << " is " << dist[i] << std::endl;

        delete[] dist;
    }

    /**
     * Implements Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
     * 
     * @param g The graph to perform Prim's algorithm on.
     * @throws std::invalid_argument If the graph has fewer than 2 vertices.
     */
    void Algorithms::Prim(const Graph& g) {
        int V = g.getVertices();
        if (V <= 1) {
            throw std::invalid_argument("Graph must have at least 2 vertices for Prim's algorithm.");
        }
        int* parent = new int[V];
        int* key = new int[V];
        bool* inMST = new bool[V]();

        for (int i = 0; i < V; ++i) {
            key[i] = INT32_MAX;
            parent[i] = -1;
        }

        MinHeap heap(V);
        key[0] = 0;
        heap.insert(0, 0);

        while (!heap.isEmpty()) {
            int u = heap.extractMin();
            inMST[u] = true;

            Node* temp = g.getAdjList()[u];
            while (temp) {
                int v = temp->vertex;
                int weight = temp->weight;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    if (heap.contains(v))
                        heap.decreaseKey(v, key[v]);
                    else
                        heap.insert(v, key[v]);
                }
                temp = temp->next;
            }
        }

        for (int i = 1; i < V; ++i)
            std::cout << parent[i] << " - " << i << std::endl;

        delete[] parent;
        delete[] key;
        delete[] inMST;
    }

    /**
     * Implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of the graph.
     * 
     * @param g The graph to perform Kruskal's algorithm on.
     * @throws std::invalid_argument If the graph has fewer than 2 vertices.
     */
    void Algorithms::Kruskal(const Graph& g) {
        int V = g.getVertices();
        if (V <= 1) {
            throw std::invalid_argument("Graph must have at least 2 vertices for Kruskal's algorithm.");
        }

        Edge* edges = new Edge[V * V];
        int edgeCount = 0;

        for (int i = 0; i < V; ++i) {
            Node* temp = g.getAdjList()[i];
            while (temp) {
                if (i < temp->vertex) {
                    edges[edgeCount++] = {i, temp->vertex, temp->weight};
                }
                temp = temp->next;
            }
        }

        // מיון ידני (selection sort)
        for (int i = 0; i < edgeCount - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < edgeCount; ++j) {
                if (edges[j].weight < edges[minIdx].weight)
                    minIdx = j;
            }
            if (minIdx != i) {
                Edge temp = edges[i];
                edges[i] = edges[minIdx];
                edges[minIdx] = temp;
            }
        }

        UnionFind uf(V);

        for (int i = 0; i < edgeCount; ++i) {
            Edge e = edges[i];
            if (!uf.connected(e.src, e.dest)) {
                uf.unite(e.src, e.dest);
                std::cout << e.src << " - " << e.dest << " weight: " << e.weight << std::endl;
            }
        }

        delete[] edges;
    }

}

