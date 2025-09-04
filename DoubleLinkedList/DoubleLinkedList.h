#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    Node<T>* prev;
    T data;
    Node<T>* next;

    Node(const T& value): prev(nullptr), data(value), next(nullptr) {}
};

template <class T>
class DoubleLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int count;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insertAtBeginning(const T& value);
        void insertAtEnd(const T& value);
        void insertAtPosition(const T& value, int position);
        void removeAtBeginning();
        void removeAtEnd();

        void displayForward() const;
        void displayBackward() const;

        bool isEmpty() const;
        void clear();
        int size() const;
};

#endif