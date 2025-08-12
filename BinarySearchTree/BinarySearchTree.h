#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

// Node structure for BST, holds data and pointers to left and right children
template <class T>
struct Node {
    T data;            // Value stored in the node
    Node<T>* left;     // Pointer to left child
    Node<T>* right;    // Pointer to right child

    // Constructor to initialize node with given value and null children
    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) class template
template <class T>
class BinarySearchTree {
private:
    Node<T>* root;  // Pointer to the root node of the BST

    // Helper method to insert a value starting from given node pointer reference
    void insertHelper(Node<T>*& node, const T& value);

    // Helper method to traverse the tree in-order (left, root, right)
    void inOrderHelper(Node<T>* node);

    // Helper method to traverse the tree pre-order (root, left, right)
    void preOrderHelper(Node<T>* node);

    // Helper method to traverse the tree post-order (left, right, root)
    void postOrderHelper(Node<T>* node);

    // Helper method to search for a value starting from given node
    Node<T>* searchHelper(Node<T>* node, const T& value);

    // Helper method to remove a node with given value starting from given node
    Node<T>* removeHelper(Node<T>* node, const T& value);

    // Helper method to find the node with minimum value in the subtree rooted at node
    Node<T>* findMinHelper(Node<T>* node);

    // Helper method to find the node with maximum value in the subtree rooted at node
    Node<T>* findMaxHelper(Node<T>* node);

    // Helper method to recursively destroy the tree and free memory
    void destroyTreeHelper(Node<T>* node);

    // Helper method to print the tree structure visually with indentation
    void printTreeHelper(Node<T>* node, int indent);

public:
    // Constructor initializes an empty BST
    BinarySearchTree();

    // Destructor frees all allocated nodes
    ~BinarySearchTree();

    // Inserts a value into the BST
    void insert(const T& value);

    // Searches for a value in the BST; returns true if found, false otherwise
    bool search(const T& value);

    // Removes a node with the given value from the BST
    void remove(const T& value);

    // Traverses and prints the BST in-order
    void inOrder();

    // Traverses and prints the BST pre-order
    void preOrder();

    // Traverses and prints the BST post-order
    void postOrder();

    // Returns the minimum value stored in the BST
    T findMin();

    // Returns the maximum value stored in the BST
    T findMax();

    // Prints the structure of the BST visually
    void printTree();
};

#endif
