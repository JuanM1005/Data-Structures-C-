#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;        // The data stored in the node
    Node<T> *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    // and set its 'next' pointer to null
    Node(const T &value) : data(value), next(nullptr) {}
};

template <class T>
class SinglyLinkedList {
    private:
        Node<T> *head; // Pointer to the first node in the list
        int count;     // Number of elements in the list

        // Helper function for recursive printing
        void printRecursiveHelper(Node<T> *current) const;

    public:
        // Constructor: initializes an empty list
        SinglyLinkedList();
        ~SinglyLinkedList();

        void insertAtBeginning(const T &value);
        void insertAtEnd(const T &value);
        void insertAtPosition(const T &value, int position);

        // Removes the first node of the list
        void removeAtBeggining();
        // Removes the last node of the list
        void removeAtEnd();
        // Removes a node at a specific position (0-based)
        void removeAtPosition(int position);

        // Removes the first node that contains the given value. Returns true if value was found and removed, false otherwise.
        bool remove(const T &value);

        // Checks if a value exists in the list
        bool contains(const T &value) const;

        bool isEmpty() const;
        int size() const;

        T getAt(int position) const;

        void clear();

        // Prints the list iteratively
        void print() const;
        // Prints the list recursively
        void printRecursive() const;

        // Removes adjacent duplicate elements from the list. Assumes the list is sorted for full deduplication.
        void removeAdjacentDuplicates();

        // Sort elements
        void sort();
};
#endif // SINGLYLINKEDLIST_H
