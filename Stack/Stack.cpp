#include "Stack.h"

template <class T, size_t MaxSize>
Stack<T, MaxSize>::Stack() {
    topIndex = -1; // Initialize stack as empty
}

template <class T, size_t MaxSize>
bool Stack<T, MaxSize>::isEmpty() const{
    return topIndex == -1;
}

template <class T, size_t MaxSize>
bool Stack<T, MaxSize>::isFull() const {
    return topIndex == MaxSize - 1;
}

template <class T, size_t MaxSize>
void Stack<T, MaxSize>::push(const T& value) {
    if (isFull()) {
        throw std::overflow_error("Stack overflow: the stack is full.");
    }
    elements[++topIndex] = value; // Increment topIndex and insert value
}

template <class T, size_t MaxSize>
void Stack<T, MaxSize>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow: the stack is empty.");
    }
    
    T removed = elements[topIndex--];
    std::cout << removed << " popped from Stack." << std::endl;
}

template <class T, size_t MaxSize>
T& Stack<T, MaxSize>::top() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot get top: the stack is empty.");
    }
    return elements[topIndex];
}

template <class T, size_t MaxSize>
const T& Stack<T, MaxSize>::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Cannot get top: the stack is empty.");
    }
    return elements[topIndex];
}

template <class T, size_t MaxSize>
int Stack<T, MaxSize>::size() {
    return topIndex + 1;
}

template <class T, size_t MaxSize>
void Stack<T, MaxSize>::display() const {
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

template <class T, size_t MaxSize>
void Stack<T, MaxSize>::display_inpop() {
    std::string pause; // variable to capture ENTER
    while (!isEmpty()) {
        std::cout << "Top: " << top() << " (press ENTER to pop)";
        std::getline(std::cin, pause);  // wait for ENTER
        pop();
    }

    std::cout << "\nStack is now empty." << std::endl;
}
