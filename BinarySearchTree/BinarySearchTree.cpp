#include "BinarySearchTree.h"

// Constructor initializes an empty tree with null root
template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

// Destructor frees all nodes recursively
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTreeHelper(root);
}

// Public insert function calls helper starting at root
template <class T>
void BinarySearchTree<T>::insert(const T& value) {
    insertHelper(root, value);
}

// Helper function to recursively insert value into the tree
template <class T>
void BinarySearchTree<T>::insertHelper(Node<T>*& node, const T& value) {
    if(node == nullptr ) {
        // Insert new node here
        node = new Node<T>(value);
    } else if (value < node->data) {
        // Insert into left subtree
        insertHelper(node->left, value);
    } else {
        // Insert into right subtree
        insertHelper(node->right, value);
    }
}

// Public inorder traversal prints nodes in ascending order
template <class T>
void BinarySearchTree<T>::inOrder() {
    inOrderHelper(root);
    std::cout << std::endl;
}

// Helper recursive inorder traversal: left, root, right
template <class T>
void BinarySearchTree<T>::inOrderHelper(Node<T>* node) {
    if(node == nullptr) return;

    inOrderHelper(node->left);
    std::cout << node->data << " - ";
    inOrderHelper(node->right);
}

// Public preorder traversal prints root before children
template <class T>
void BinarySearchTree<T>::preOrder() {
    preOrderHelper(root);
    std::cout << std::endl;
}

// Helper recursive preorder traversal: root, left, right
template <class T>
void BinarySearchTree<T>::preOrderHelper(Node<T>* node) {
    if(node == nullptr) return;

    std::cout << node->data << " - ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
}

// Public postorder traversal prints children before root
template <class T>
void BinarySearchTree<T>::postOrder() {
    postOrderHelper(root);
    std::cout << std::endl;
}

// Helper recursive postorder traversal: left, right, root
template <class T>
void BinarySearchTree<T>::postOrderHelper(Node<T>* node) {
    if(node == nullptr) return;

    postOrderHelper(node->left);
    postOrderHelper(node->right);
    std::cout << node->data << " - ";
}

// Recursive helper to search for a value starting at node
template <class T>
Node<T>* BinarySearchTree<T>::searchHelper(Node<T>* node, const T& value) {
    if(node == nullptr || node->data == value)  {
        return node; // Found node or nullptr if not found
    } else if (value < node->data) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

// Public search returns true if value found, false otherwise
template <class T>
bool BinarySearchTree<T>::search(const T& value) {
    return searchHelper(root, value) != nullptr; 
}

// Recursive helper to remove a node with given value
template <class T>
Node<T>* BinarySearchTree<T>::removeHelper(Node<T>* node, const T& value) {
    if (node == nullptr) return nullptr;

    if (value < node->data) {
        // Continue in left subtree
        node->left = removeHelper(node->left, value);
    } else if (value > node->data) {
        // Continue in right subtree
        node->right = removeHelper(node->right, value);
    } else {
        // Node to remove found
        if (node->left == nullptr && node->right == nullptr) {
            // Case 1: Leaf node
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            // Case 2: Only right child
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            // Case 2: Only left child
            Node<T>* temp = node->left;
            delete node;
            return temp;
        } else {
            // Case 3: Two children
            Node<T>* minNode = findMinHelper(node->right); // Find inorder successor
            node->data = minNode->data;                     // Copy successor's data
            node->right = removeHelper(node->right, minNode->data); // Remove successor
        }
    }

    return node; 
}

// Public remove calls recursive helper starting at root
template <class T>
void BinarySearchTree<T>::remove(const T& value) {
    root = removeHelper(root, value);
}

// Helper to find the node with minimum value starting at node
template <class T>
Node<T>* BinarySearchTree<T>::findMinHelper(Node<T>* node) {
    while(node && node->left != nullptr) {
        node = node->left;
    }
    return node;
} 

// Public function to get minimum value in tree
template <class T>
T BinarySearchTree<T>::findMin() {
    if(root == nullptr) {
        throw std::runtime_error("The tree is empty, cannot find minimum.");
    }

    Node<T>* minNode = findMinHelper(root);
    return minNode->data;
}

// Helper to find node with maximum value starting at node
template <class T>
Node<T>* BinarySearchTree<T>::findMaxHelper(Node<T>* node) {
    while(node && node->right != nullptr) {
        node = node->right;
    }
    return node;
} 

// Public function to get maximum value in tree
template <class T>
T BinarySearchTree<T>::findMax() {
    if(root == nullptr) {
        throw std::runtime_error("The tree is empty, cannot find maximum.");
    }

    Node<T>* maxNode = findMaxHelper(root);
    return maxNode->data;
}

// Helper function to recursively destroy all nodes starting at node
template <class T>
void BinarySearchTree<T>::destroyTreeHelper(Node<T>* node) {
    if(node != nullptr){
        destroyTreeHelper(node->left);
        destroyTreeHelper(node->right);
        delete node; // Delete current node
    }
}

// Helper to print the tree structure visually with indentation
template <class T>
void BinarySearchTree<T>::printTreeHelper(Node<T>* node, int indent) {
    if (node == nullptr) return;

    // Print right subtree with increased indent
    printTreeHelper(node->right, indent + 4);

    // Print current node with indentation
    if (indent > 0)
        std::cout << std::setw(indent) << ' ';
    std::cout << node->data << std::endl;

    // Print left subtree with increased indent
    printTreeHelper(node->left, indent + 4);
}

// Public function to print tree visually
template <class T>
void BinarySearchTree<T>::printTree() {
    std::cout << "Visual representation of the tree:\n";
    printTreeHelper(root, 0);
}
