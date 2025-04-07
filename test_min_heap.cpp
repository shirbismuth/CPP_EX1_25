#include "min_heap.hpp"
#include <cassert>
#include <iostream>

// Test inserting elements into the MinHeap.
void testMinHeapInsert() {
    graph::MinHeap heap(10);
    heap.insert(0, 10);
    heap.insert(1, 5);
    heap.insert(2, 20);
    assert(heap.extractMin() == 1);  // הקודקוד עם המרחק הקטן ביותר

}

// Test decreasing the key (distance) of an element in the MinHeap.
void testMinHeapDecreaseKey() {
    graph::MinHeap heap(10);
    heap.insert(0, 10);
    heap.insert(1, 5);
    heap.decreaseKey(0, 3);  // עדכון המרחק של קודקוד 0
    assert(heap.extractMin() == 0);  // הקודקוד עם המרחק הקטן ביותר

}

// Test extracting the minimum element from the MinHeap.
void testMinHeapExtractMin() {
    graph::MinHeap heap(10);
    heap.insert(0, 10);
    heap.insert(1, 5);
    heap.insert(2, 20);
    assert(heap.extractMin() == 1);  // הקודקוד עם המרחק הקטן ביותר
    assert(heap.extractMin() == 0);  // לאחר מכן קודקוד 0

}

// Test checking if an element exists in the MinHeap.
void testMinHeapContains() {
    graph::MinHeap heap(10);
    heap.insert(0, 10);
    assert(heap.contains(0) == true);  // קודקוד 0 נמצא
    assert(heap.contains(1) == false); // קודקוד 1 לא נמצא

}

// Test checking if the MinHeap is empty.
void testMinHeapIsEmpty() {
    graph::MinHeap heap(10);
    assert(heap.isEmpty() == true);  // תור ריק
    heap.insert(0, 10);
    assert(heap.isEmpty() == false); // תור לא ריק

}


