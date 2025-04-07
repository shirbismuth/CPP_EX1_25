#include <iostream>  // לכלול את ספריית ה־I/O
#include "test_algo.cpp"       // טסטים של אלגוריתמים
#include "test_graph.cpp"      // טסטים לגרף
#include "test_min_heap.cpp"   // טסטים עבור MinHeap
#include "test_queue.cpp"      // טסטים עבור Queue
#include "test_union_find.cpp" // טסטים עבור UnionFind

int main() {
    std::cout << "Running tests..." << std::endl;

    testBFS();
    testDFS();
    testDijkstra();
    testPrim();
    testKruskal();
    testGraphAddEdge();
    testGraphRemoveEdge();
    testGraphAddEdgeInvalidIndex();
    testGraphRemoveEdgeNotFound();
    testMinHeapInsert();
    testMinHeapDecreaseKey();
    testMinHeapExtractMin();
    testMinHeapContains();
    testMinHeapIsEmpty();
    testQueueEnqueue();
    testQueueDequeue();
    testQueueIsEmpty();
    testQueueOverflow();
    testQueueUnderflow();
    testUnionFindUnite();
    testUnionFindConnected();
    testUnionFindFind();
    testUnionFindInvalidIndex();

    std::cout << "Finish Test" << std::endl;

    return 0;
}
