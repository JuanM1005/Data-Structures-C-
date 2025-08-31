#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include <stdexcept>

// Node structure to hold the data and a pointer to the next node
template <class T>
struct Node {
    T data;           // The data stored in the node
    Node<T>* next;    // Pointer to the next node in the queue

    // Constructor to initialize the node with a value and null next pointer
    Node(const T& value) : data(value), next(nullptr) {}
};

// LinkedQueue class implementing a queue using linked nodes
template <class T>
    class LinkedQueue {
    private:
        Node<T>* front;    // Pointer to the front node of the queue
        Node<T>* rear;     // Pointer to the rear node of the queue
        int count;         // Number of elements in the queue

        // Helper function for recursive printing from a given node
        void printRecursiveHelper(Node<T>* current);

    public:
        // Constructor initializes an empty queue
        LinkedQueue();

        // Destructor releases all allocated nodes
        ~LinkedQueue();

        // Adds an element to the rear of the queue
        void enqueue(const T& value);

        // Removes the element from the front of the queue
        void dequeue();

        // Returns the element at the front of the queue (throws if empty)
        T getFront() const;

        // Returns the element at the rear of the queue (throws if empty)
        T getRear() const;

        // Returns true if the queue is empty, false otherwise
        bool isEmpty() const;

        // Returns the number of elements currently in the queue
        int size() const;

        // Removes all elements from the queue
        void clear();

        // Prints all elements from front to rear iteratively
        void print();

        // Prints all elements from front to rear recursively
        void printRecursive();
};

#endif
