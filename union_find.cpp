#include "union_find.hpp"
#include <stdexcept>

namespace graph {

    // Constructor: Initializes the Union-Find data structure with `n` elements.
    UnionFind::UnionFind(int n) : size(n) {
        if (n <= 0) {
            throw std::invalid_argument("Size of UnionFind must be positive.");
        }
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Destructor: Cleans up dynamically allocated memory.
    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    // Finds the representative (root) of the set containing `x` with path compression.
    int UnionFind::find(int x) {
        if (x < 0 || x >= size) {
            throw std::out_of_range("Index out of range in find operation.");
        }
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Unites the sets containing `x` and `y` using union by rank.
    void UnionFind::unite(int x, int y) {
        if (x < 0 || x >= size || y < 0 || y >= size) {
            throw std::out_of_range("Index out of range in unite operation.");
        }
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }

    // Checks if `x` and `y` are in the same set.
    bool UnionFind::connected(int x, int y) {
        if (x < 0 || x >= size || y < 0 || y >= size) {
            throw std::out_of_range("Index out of range in connected operation.");
        }
        return find(x) == find(y);
    }

} // namespace graph
