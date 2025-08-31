#include "Stack.h"

Stack::Stack() {
    topIndex = -1; // Initialize stack as empty
}

bool Stack::isEmpty() {
    return topIndex == -1;
}

bool Stack::isFull() {
    return topIndex == MAX - 1;
}

void Stack::push(int value) {
    if (isFull()) {
        throw std::runtime_error("Stack overflow: the stack is full.");
    }
    elements[++topIndex] = value; // Increment topIndex and insert value
}

void Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow: the stack is empty.");
    }
    topIndex--; // Simply decrease topIndex
}

int Stack::top() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot get top: the stack is empty.");
    }
    return elements[topIndex];
}

void Stack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    // Print elements from top to bottom
    for (int i = topIndex; i >= 0; i--) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::display_inpop() {
    std::string pause; // variable to capture ENTER
    while (!isEmpty()) {
        std::cout << "Top: " << top() << " (press ENTER to pop)";
        std::getline(std::cin, pause);  // wait for ENTER
        pop();
    }

    std::cout << "\nStack is now empty." << std::endl;
}
