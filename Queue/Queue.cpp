#include "Queue.h"

template <class T, size_t MaxSize>
Queue<T, MaxSize>::Queue() : front(0), rear(MaxSize - 1), count(0) {}

template <class T, size_t MaxSize>
bool Queue<T, MaxSize>::isEmpty() const {
    return count == 0;
}

template <class T, size_t MaxSize>
bool Queue<T, MaxSize>::isFull() const {
    return count == MaxSize;
}

template <class T, size_t MaxSize>
void Queue<T, MaxSize>::enqueue(const T& value) {
    if (isFull()) {
        throw std::overflow_error("Queue is full. Cannot enqueue.");
    }
    rear = (rear + 1) % MaxSize;
    elements[rear] = value;
    count++;
}

template <class T, size_t MaxSize>
void Queue<T, MaxSize>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot dequeue.");
    }
    front = (front + 1) % MaxSize;
    count--;
}

template <class T, size_t MaxSize>
T& Queue<T, MaxSize>::getFront() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return elements[front];
}

template <class T, size_t MaxSize>
const T& Queue<T, MaxSize>::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return elements[front];
}

template <class T, size_t MaxSize>
T& Queue<T, MaxSize>::getRear() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return elements[rear];
}

template <class T, size_t MaxSize>
const T& Queue<T, MaxSize>::getRear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return elements[rear];
}

template <class T, size_t MaxSize>
size_t Queue<T, MaxSize>::size() const {
    return count;
}

template <class T, size_t MaxSize>
void Queue<T, MaxSize>::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    size_t current = front;
    for (size_t i = 0; i < count; i++) {
        std::cout << elements[current] << " ";
        current = (current + 1) % MaxSize;
    }
    std::cout << std::endl;
}