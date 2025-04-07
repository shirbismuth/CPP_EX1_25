#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph{

    struct Node
        {
            int vertex;
            int weight;
            Node* next;

            Node(int v,int w,Node* n=nullptr): vertex(v), weight(w),next(n)
            {}
        };

    class Graph {
        private:
             int vertices;
             Node** list;
        
        public:
            Graph(int vertices);
            ~Graph();
            void addEdge(int src, int des, int weight =1);
            void removeEdge(int src, int des);
            void print_graph() const;
            int getVertices() const;
            Node** getAdjList() const;

        

            
    };
}

#endif