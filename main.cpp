#include <iostream>
#include "graph.hpp"
#include "algorithms.hpp"

using namespace std;
using namespace graph;

int main() {
    // יצירת גרף עם 6 קודקודים
    Graph g(6);

    // הוספת קשתות
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    cout << "\n----- print graph-----\n";
    g.print_graph();

    cout << "\n----- BFS from 0-----\n";
    Algorithms::BFS(g, 0);

    cout << "\n----- DFS from 0-----\n";
    Algorithms::DFS(g, 0);

    cout << "\n-----Dijkstra from 0 -----\n";
    Algorithms::Dijkstra(g, 0);

    cout << "\n-----  (Prim) -----\n";
    Algorithms::Prim(g);

    cout << "\n-----  (Kruskal) -----\n";
    Algorithms::Kruskal(g);

    return 0;
}
