#include "min_heap.hpp"
#include <stdexcept>

namespace graph {

    // Constructor: Initializes the MinHeap with a given capacity.
    MinHeap::MinHeap(int cap) : size(0), capacity(cap) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be greater than 0");
        }
        heap = new HeapNode[cap];
        pos = new int[cap];
        for (int i = 0; i < cap; ++i)
            pos[i] = -1;
    }

    // Destructor: Cleans up dynamically allocated memory.
    MinHeap::~MinHeap() {
        delete[] heap;
        delete[] pos;
    }

    // Checks if the heap is empty.
    bool MinHeap::isEmpty() const {
        return size == 0;
    }

    // Checks if a vertex exists in the heap.
    bool MinHeap::contains(int vertex) const {
        if (vertex < 0 || vertex >= capacity) {
            throw std::out_of_range("Vertex index out of range");
        }
        return pos[vertex] != -1;
    }

    // Inserts a vertex with a distance into the heap.
    void MinHeap::insert(int vertex, int dist) {
        if (vertex < 0 || vertex >= capacity) {
            throw std::out_of_range("Vertex index out of range");
        }
        if (dist < 0) {
            throw std::invalid_argument("Distance must be non-negative");
        }
        if (size >= capacity) {
            throw std::overflow_error("Heap capacity exceeded");
        }
        heap[size] = {vertex, dist};
        pos[vertex] = size;
        heapifyUp(size);
        size++;
    }

    // Decreases the distance of a vertex in the heap.
    void MinHeap::decreaseKey(int vertex, int dist) {
        if (vertex < 0 || vertex >= capacity || pos[vertex] == -1) {
            throw std::out_of_range("Vertex not found in heap");
        }
        if (dist < 0) {
            throw std::invalid_argument("Distance must be non-negative");
        }
        int i = pos[vertex];
        heap[i].dist = dist;
        heapifyUp(i);
    }

    // Extracts the vertex with the minimum distance from the heap.
    int MinHeap::extractMin() {
        if (isEmpty()) {
            throw std::underflow_error("Heap is empty");
        }
        int root = heap[0].vertex;
        heap[0] = heap[size - 1];
        pos[heap[0].vertex] = 0;
        pos[root] = -1;
        size--;
        heapifyDown(0);
        return root;
    }

    // Moves a node up the heap to maintain the heap property.
    void MinHeap::heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent].dist > heap[idx].dist) {
                swap(parent, idx);
                pos[heap[parent].vertex] = parent;
                pos[heap[idx].vertex] = idx;
                idx = parent;
            } else break;
        }
    }

    // Moves a node down the heap to maintain the heap property.
    void MinHeap::heapifyDown(int idx) {
        int smallest = idx;
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            if (left < size && heap[left].dist < heap[smallest].dist) smallest = left;
            if (right < size && heap[right].dist < heap[smallest].dist) smallest = right;
            if (smallest != idx) {
                swap(smallest, idx);
                pos[heap[smallest].vertex] = smallest;
                pos[heap[idx].vertex] = idx;
                idx = smallest;
            } else break;
        }
    }

    // Swaps two nodes in the heap and updates their positions.
    void MinHeap::swap(int i, int j) {
        HeapNode temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    
        // אם את משתמשת במערך pos לעקוב אחרי מיקומים:
        pos[heap[i].vertex] = i;
        pos[heap[j].vertex] = j;
    }

} // namespace graph
