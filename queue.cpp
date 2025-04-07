#include "queue.hpp"
#include <stdexcept>

namespace graph {

    // Constructor: Initializes the Queue with a given capacity.
    Queue::Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be greater than 0");
        }
        data = new int[capacity];
    }

    // Destructor: Cleans up dynamically allocated memory.
    Queue::~Queue() {
        delete[] data;
    }

    // Adds an element to the rear of the queue.
    void Queue::enqueue(int x) {
        if (size == capacity) {
            throw std::overflow_error("Queue is full. Cannot enqueue.");
        }
        data[rear] = x;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Removes and returns the front element of the queue.
    int Queue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty. Cannot dequeue.");
        }
        int val = data[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    // Checks if the queue is empty.
    bool Queue::isEmpty() const {
        return size == 0;
    }

} // namespace graph
