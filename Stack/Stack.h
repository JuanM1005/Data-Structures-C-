#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept>

class Stack {
    private:
        static const int MAX = 100;
        int elements[MAX];
        int topIndex;

    public:
        Stack();                 
        bool isEmpty();        
        bool isFull();        
        void push(int value);  
        void pop();        
        int top();       
        void display();          
};

#endif
