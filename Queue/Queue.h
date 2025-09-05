#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T, size_t MaxSize = 100>
class Queue {
    private:
        T elements[MaxSize];
        size_t front;
        size_t rear;
        size_t count;

    public:
        Queue();
        
        bool isEmpty() const;
        bool isFull() const;
        
        void enqueue(const T& value);
        void dequeue();
        
        T& getFront();
        const T& getFront() const;

        T& getRear();
        const T& getRear() const;

        size_t size() const;
        
        void display() const;
};

#endif
