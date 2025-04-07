#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace graph {

    class Queue {
        int* data;
        int front, rear, size, capacity;
    public:
        Queue(int capacity);
        ~Queue();
        void enqueue(int x);
        int dequeue();
        bool isEmpty() const;
    };

}

#endif
