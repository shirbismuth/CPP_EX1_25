#include "queue.hpp"
#include <cassert>
#include <iostream>

// Test enqueuing elements into the queue.
void testQueueEnqueue() {
    graph::Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    assert(q.dequeue() == 10);  

}

// Test dequeuing elements from the queue.
void testQueueDequeue() {
    graph::Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    assert(q.dequeue() == 10);  // הראשון שנכנס יוצא ראשון
    assert(q.dequeue() == 20);  // השני יוצא אחרי
}

// Test checking if the queue is empty.
void testQueueIsEmpty() {
    graph::Queue q(5);
    assert(q.isEmpty() == true);  // התור ריק אחרי יצירה
    q.enqueue(10);
    assert(q.isEmpty() == false);  // התור לא ריק אחרי הכנסת איבר

}

// Test handling overflow when the queue is full.
void testQueueOverflow() {
    graph::Queue q(2);
    q.enqueue(10);
    q.enqueue(20);
    try {
        q.enqueue(30);  // יגרום לשגיאה
        assert(false);  //  הטסט נכשל
    } catch (const std::overflow_error& e) {
        std::cout << "testQueueOverflow passed! " << e.what() << std::endl;
    }
}

// Test handling underflow when the queue is empty.
void testQueueUnderflow() {
    graph::Queue q(2);
    try {
        q.dequeue();  // יגרום לשגיאה כי התור ריק
        assert(false);  //  הטסט נכשל
    } catch (const std::underflow_error& e) {
        std::cout << "testQueueUnderflow passed! " << e.what() << std::endl;
    }
}

