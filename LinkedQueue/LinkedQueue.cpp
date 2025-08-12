#include "LinkedQueue.h"

// Constructor initializes an empty queue with null pointers and zero count
template <class T>
LinkedQueue<T>::LinkedQueue() : front(nullptr), rear(nullptr), count(0) {}

// Destructor clears the queue, freeing all allocated nodes
template <class T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

// Adds a new element at the rear of the queue
template <class T>
void LinkedQueue<T>::enqueue(const T& value) {
    Node<T>* newNode = new Node<T>(value);  // Create new node

    if (isEmpty()) {
        // If queue is empty, new node is both front and rear
        front = newNode;
    } else {
        // Otherwise, link new node after rear
        rear->next = newNode;
    }

    rear = newNode;  // Update rear pointer to new node
    count++;         // Increment element count
}

// Removes the element at the front of the queue
template <class T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty, cannot dequeue.");
    }

    Node<T>* temp = front;    // Temporarily store front node
    front = front->next;      // Move front pointer to next node

    if (front == nullptr) {
        // If queue becomes empty, reset rear pointer as well
        rear = nullptr;
    }

    delete temp;  // Free memory of old front node
    count--;      // Decrement element count
}

// Returns true if the queue has no elements
template <class T>
bool LinkedQueue<T>::isEmpty() const {
    return front == nullptr;
}

// Returns the data of the front node (throws if queue is empty)
template <class T>
T LinkedQueue<T>::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty, cannot get front.");
    }

    return front->data;
}

// Returns the data of the rear node (throws if queue is empty)
template <class T>
T LinkedQueue<T>::getRear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty, cannot get rear.");
    }

    return rear->data;
}

// Returns the number of elements currently in the queue
template <class T>
int LinkedQueue<T>::size() const {
    return count;
}

// Clears the entire queue, freeing all nodes
template <class T>
void LinkedQueue<T>::clear() {
    while (!isEmpty()) {
        dequeue();  // Repeatedly remove from front until empty
    }
}

// Prints the queue iteratively from front to rear
template <class T>
void LinkedQueue<T>::print() {
    if (isEmpty()) return;

    Node<T>* temp = front;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;
}

// Prints the queue recursively from front to rear
template <class T>
void LinkedQueue<T>::printRecursive() {
    printRecursiveHelper(front);
    std::cout << "nullptr" << std::endl;
}

// Helper recursive function to print each node
template <class T>
void LinkedQueue<T>::printRecursiveHelper(Node<T>* current) {
    if (current == nullptr) {
        return;  // Base case: reached end of queue
    }

    std::cout << current->data << " -> ";
    printRecursiveHelper(current->next);  // Recursive call on next node
}
