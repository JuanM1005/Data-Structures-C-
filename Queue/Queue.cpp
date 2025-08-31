#include "Queue.h"

Queue::Queue() {
    front = 0;
    rear = -1;
}

bool Queue::isEmpty() {
    return rear < front;
}

bool Queue::isFull() {
    return rear == MAX - 1;
}

void Queue::enqueue(int value) {
    if(isFull()) {
        throw::overflow_error("Queue is full. Cannot enqueue.");
    }

    elements[++rear] = value;
}

void Queue::dequeue() {
    if(isEmpty()) {
        throw::underflow_error("Queue is empty. Cannot dequeue.");
    }

    front++;
}

int Queue::getFront() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. Cannot get front.");
    }

    return elements[front];
}   

void Queue::display() {
    if(isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    for(int i = front; i <= rear; i++) {
        std::cout << elements[i] << " ";
    }

    std::cout << std::endl;
}

void Queue::display_indeuqeue() {
    std::string pause; // variable to capture ENTER
    while(!isEmpty()) {
        std::cout << "Front: " << getFront() << " (press ENTER to dequeue)";
        std::getline(std::cin, pause); // wait for ENTER
        dequeue();
    }

     std::cout << "Queue now is empty." << std::endl;
}