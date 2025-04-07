#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

namespace graph {

    class UnionFind {
        int* parent;
        int* rank;
        int size;
    public:
        UnionFind(int n);
        ~UnionFind();
        int find(int x);
        void unite(int x, int y);
        bool connected(int x, int y);
    };

}

#endif
