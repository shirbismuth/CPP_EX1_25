#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "graph.hpp"
#include <vector>
#include <stdexcept> 

namespace graph {

    class Algorithms {
        public:
        static void BFS(const Graph& g, int start);
        static void DFS(const Graph& g, int start);
        static void Dijkstra(const Graph& g, int src);
        static void Prim(const Graph& g);
        static void Kruskal(const Graph& g);
    };

    struct Edge {
        int src, dest, weight;
    };

} // namespace graph

#endif // ALGORITHMS_HPP

