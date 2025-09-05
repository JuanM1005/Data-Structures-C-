#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <class T, size_t MaxSize = 100>
class Stack {
    private:
        T elements[MaxSize];
        int topIndex;

    public:
        Stack();
        bool isEmpty() const;
        bool isFull() const;
        void push(const T& value);
        void pop();
        T& top();
        const T& top() const;
        int size();
        void display() const;
        void display_inpop();
};

#endif

