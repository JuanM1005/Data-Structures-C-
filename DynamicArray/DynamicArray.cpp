#include "DynamicArray.h"

template <class T>
DynamicArray<T>::DynamicArray() {
    capacity = 10;                   // Initial capacity of the array
    array = new T[capacity];        // Allocate memory for the array
    count = 0;                      // Initially, no elements stored
    increment = 10;                 // Amount to increase capacity when expanding
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;                 // Release the allocated memory
}

template <class T>
bool DynamicArray<T>::isEmpty() const {
    return count == 0;              // True if no elements stored
}

template <class T>
bool DynamicArray<T>::isFull() const {
    return count == capacity;       // True if array is at full capacity
}

template <class T>
size_t DynamicArray<T>::size() const {
    return count;                  // Return the number of stored elements
}

template <class T>
void DynamicArray<T>::addAtBeginning(const T& element) {
    if (isFull()) expand();        // Expand array if full

    // Shift elements one position right to make space at index 0
    for (size_t i = count; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = element;            // Insert new element at the start
    count++;                      // Increment element count
}

template <class T>
void DynamicArray<T>::addAtEnd(const T& element) {
    if (isFull()) expand();        // Expand array if full

    array[count++] = element;      // Add element at the end and increment count
}

template <class T>
void DynamicArray<T>::addAtPosition(const T& element, size_t pos) {
    if (pos > count) {
        throw std::out_of_range("Error: Invalid position.");
    }

    if (isFull()) expand();

    // Shift elements right from pos to end to make space
    for (size_t i = count; i > pos; --i) {
        array[i] = array[i - 1];
    }

    array[pos] = element;          // Insert element at specified position
    count++;
}

template <class T>
void DynamicArray<T>::removeFromBeginning() {
    if (isEmpty()) {
        throw std::out_of_range("Error: The array is empty.");
    }

    // Shift elements left to overwrite the first element
    for (size_t i = 0; i < count - 1; i++) {
        array[i] = array[i + 1];
    }

    count--;
}

template <class T>
void DynamicArray<T>::removeFromEnd() {
    if (isEmpty()) {
        throw std::out_of_range("Error: The array is empty.");
    }

    count--;  // Simply decrement count, no need to shift
}

template <class T>
void DynamicArray<T>::removeFromPosition(size_t pos) {
    if (pos >= count) {
        throw std::out_of_range("Error: Invalid position.");
    }

    if (isEmpty()) {
        throw std::out_of_range("Error: The array is empty.");
    }

    // Shift elements left from pos+1 to end to overwrite the element at pos
    for (size_t i = pos; i < count - 1; i++) {
        array[i] = array[i + 1];
    }

    count--;
}

template <class T>
void DynamicArray<T>::expand() {
    capacity += increment;             // Increase capacity
    T* newArray = new T[capacity];     // Allocate new array

    // Copy elements to new array
    for (size_t i = 0; i < count; i++) {
        newArray[i] = array[i];
    }

    delete[] array;                   // Delete old array
    array = newArray;                 // Point to new array
}

template <class T>
void DynamicArray<T>::shrink() {
    if (size() == capacity) return;   // If no unused space, do nothing

    capacity -= increment;            // Reduce capacity
    T* newArray = new T[capacity];   // Allocate smaller array

    // Copy existing elements
    for (size_t i = 0; i < count; i++) {
        newArray[i] = array[i];
    }

    delete[] array;                  // Delete old array
    array = newArray;                // Update pointer
}

template <class T>
T* DynamicArray<T>::search(const T& element) {
    for (size_t i = 0; i < count; i++) {
        if (element == array[i]) {
            return &array[i];        // Return pointer to element found
        }
    }
    return nullptr;                   // Return nullptr if not found
}

template <class T>
T DynamicArray<T>::operator[](size_t pos) const {
    if (pos >= count) {
        throw std::out_of_range("Error: Invalid position.");
    }
    return array[pos];                // Return element at pos
}

template <class T>
DynamicArray<T*> DynamicArray<T>::searchAll(const T& element) {
    DynamicArray<T*> results;         // Dynamic array to store pointers to matches
    for (size_t i = 0; i < count; i++) {
        if (element == array[i]) {
            results.addAtEnd(&array[i]);  // Add address of matched element
        }
    }
    return results;
}

template <class T>
void DynamicArray<T>::display() const {
    if (isEmpty()) {
        throw std::out_of_range("Error: The array is empty.");
    }

    for (size_t i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}
