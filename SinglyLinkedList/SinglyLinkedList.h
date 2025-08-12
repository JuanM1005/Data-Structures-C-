#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <class T>
class SinglyLinkedList {
    private:
        Node<T>* head;
        int count;
        void printRecursiveHelper(Node<T>* current);
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void insertAtBeggining(const T& value);
        void insertAtEnd(const T& value);
        void insertAtPosition(const T& value, int position);
        void removeAtBeggining();
        void removeAtEnd();
        void removeAtPosition(int position);
        void remove(const T& value);
        
        bool contains(const T& value);
        bool isEmpty();
        int size() const;
        T getAt(int position) const;

        void clear();
        void print();
        void printRecursive();
};

#endif