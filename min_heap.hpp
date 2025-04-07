#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

namespace graph {

    class MinHeap {
        struct HeapNode {
            int vertex;
            int dist;
        };

        HeapNode* heap;
        int* pos;
        int size ,capacity;

        void heapifyUp(int idx);
        void heapifyDown(int idx);

    public:
        MinHeap(int capacity);
        ~MinHeap();
        void insert(int vertex, int dist);
        bool isEmpty() const;
        int extractMin();
        void decreaseKey(int vertex, int dist);
        bool contains(int vertex) const;
        void swap(int i, int j);
    };

}

#endif
