#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

// Template structure for a node in a singly linked list
template <class T>
    struct Node {
        T data;              // The data stored in the node
        Node<T>* next;       // Pointer to the next node in the list

        // Constructor to initialize a node with a given value
        // and set its 'next' pointer to null
        Node(const T& value) : data(value), next(nullptr) {}
    };

    // Template class for a singly linked list
    template <class T>
    class SinglyLinkedList {
        private:
            Node<T>* head;   // Pointer to the first node in the list
            int count;       // Number of elements in the list

            // Helper function for recursive printing
            void printRecursiveHelper(Node<T>* current);

        public:
            // Constructor: initializes an empty list
            SinglyLinkedList();

            // Destructor: releases all allocated memory
            ~SinglyLinkedList();

            // Inserts a new node at the beginning of the list
            void insertAtBeggining(const T& value);

            // Inserts a new node at the end of the list
            void insertAtEnd(const T& value);

            // Inserts a new node at a specific position in the list
            void insertAtPosition(const T& value, int position);

            // Removes the first node of the list
            void removeAtBeggining();

            // Removes the last node of the list
            void removeAtEnd();

            // Removes a node at a specific position
            void removeAtPosition(int position);

            // Removes the first node that contains the given value
            void remove(const T& value);

            // Checks if a value exists in the list
            bool contains(const T& value);

            // Checks if the list is empty
            bool isEmpty();

            // Returns the number of elements in the list
            int size() const;

            // Gets the value at a specific position
            T getAt(int position) const;

            // Clears the list, deleting all nodes
            void clear();

            // Prints the list iteratively
            void print();

            // Prints the list recursively
            void printRecursive();
};

#endif
