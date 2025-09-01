#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue {
    private:
        static const int MAX = 100;  // Maximum size of the queue
        int elements[MAX];
        int front;
        int rear;

    public:
        Queue();                
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        void dequeue();
        int getRear();
        int getFront();
        void display();
        void display_indeuqeue();
};

#endif
