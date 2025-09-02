#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>

// Template class for a dynamic array of type T
template <class T>
class DynamicArray {
private:
    T* array;            // Pointer to the dynamic array
    size_t capacity;     // Total capacity of the array
    size_t count;        // Current number of elements stored
    size_t increment;    // Increment size to expand the array when full

public:
    // Constructor
    DynamicArray();

    // Destructor
    ~DynamicArray();

    // Check if the array is empty
    bool isEmpty() const;

    // Check if the array is full (count == capacity)
    bool isFull() const;

    // Get the current number of elements stored
    size_t size() const;

    // Add an element at the beginning of the array
    void addAtBeginning(const T& element);

    // Add an element at the end of the array
    void addAtEnd(const T& element);

    // Add an element at a specific position (0-based index)
    void addAtPosition(const T& element, size_t pos);

    // Remove the element at the beginning of the array
    void removeFromBeginning();

    // Remove the element at the end of the array
    void removeFromEnd();

    // Remove the element at a specific position
    void removeFromPosition(size_t pos);

    // Expand the array capacity by the increment value
    void expand();

    // Shrink the array capacity if much space is unused
    void shrink();

    // Search for an element and return a pointer to it (or nullptr if not found)
    T* search(const T& element);

    // Overload operator[] to access element at position pos (read-only)
    T operator[](size_t pos) const;

    // Search for all occurrences of element and return a dynamic array of pointers to these elements
    DynamicArray<T> searchAll(const T& element);

    // Display the contents of the array to the console
    void display() const;
};

#endif
