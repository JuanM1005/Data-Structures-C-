#include "SinglyLinkedList.h"

// Constructor: initializes an empty list
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), count(0) {}

// Destructor: clears all nodes to free memory
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

// Inserts a new node at the beginning of the list
template <class T>
void SinglyLinkedList<T>::insertAtBeginning(const T& value) {
    Node<T>* newNode = new Node<T>(value); 
    newNode->next = head;                  
    head = newNode;                        
    count++;                               
}

// Inserts a new node at the end of the list
template <class T>
void SinglyLinkedList<T>::insertAtEnd(const T& value) {
    Node<T>* newNode = new Node<T>(value); 

    if(isEmpty()) {                         // if list is empty, new node is head
        head = newNode;
    } else {
        Node<T>* temp = head;
        // traverse to last node
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;               
    }
    count++;                                
}

// Inserts a new node at a given position (0-based)
template <class T>
void SinglyLinkedList<T>::insertAtPosition(const T& value, int position) {
    // check for valid position
    if(position < 0 || position >= count) {
        throw std::out_of_range("Index out of range");
    }

    // if position is 0, insert at beginning
    if(position == 0) {
        insertAtBeginning(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;

    // traverse to the node before the insertion point
    for(int i = 0; i < position; i++) {
        temp = temp->next;
    }

    // insert new node after temp
    newNode->next = temp->next; 
    temp->next = newNode;
    count++;  
}

// Removes the first node of the list
template <class T>
void SinglyLinkedList<T>::removeAtBeggining() {
    if(isEmpty()) return;

    Node<T>* temp = head;      // save current head
    head = head->next;         // update head to next node
    delete temp;               // delete old head
    count--;                   // decrease count
}

// Removes the last node of the list
template <class T>
void SinglyLinkedList<T>::removeAtEnd() {
    if(isEmpty()) return;

    if(head->next == nullptr) {  // if only one element
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head;
        // traverse until penultimate node (node before last)
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;      // delete last node
        temp->next = nullptr;   // set penultimate node's next to nullptr
    }

    count--;  // decrease count
}

// Removes node at a specific position (1-based)
template <class T>
void SinglyLinkedList<T>::removeAtPosition(int position) {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Index out of range.");
    }
    
    if (position == 0) {
        removeAtBeggining();
        return;
    }

    Node<T>* current = head;

    for(int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    Node<T>* temp = current->next; // Node to be deleted
    current->next = temp->next; // bypass the node
    delete temp;
    count--;
}

// Removes first node containing the specified value
template <class T>
bool SinglyLinkedList<T>::remove(const T& value) {
    if (isEmpty()) {
        return false;
    }

    // if value is at the head node
    if (head->data == value) {
        removeAtBeggining();
        return true;
    }

    Node<T>* current = head;

    // traverse until we find node before the node with the value
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node<T>* temp = current->next;          // node to remove
        current->next = current->next->next;    // bypass node
        delete temp;                            
        count--;                               
        return true;
    } else {
        return false;
    }
}

// Checks if the list contains a given value
template <class T>
bool SinglyLinkedList<T>::contains(const T& value) const {
    if(isEmpty()) return false;

    Node<T>* temp = head;
    while(temp != nullptr) {
        if(temp->data == value) {
            std::cout << "The list contains the value: " << value << std::endl;
            return true;
        }
        temp = temp->next;
    }

    std::cout << "The list doesn't contain the value: " << value << std::endl;
    return false;
}

// Checks if the list is empty
template <class T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

// Returns the number of elements in the list
template <class T>
int SinglyLinkedList<T>::size() const {
    return count;
}

// Returns the data at a given position (0-based)
template <class T>
T SinglyLinkedList<T>::getAt(int position) const {
    if(position < 0 || position >= count) {   
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for(int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

// Clears the list by deleting all nodes
template <class T>
void SinglyLinkedList<T>::clear() {
    while(!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;  // reset count to zero
}

// Prints the list iteratively
template <class T>
void SinglyLinkedList<T>::print() const {
    if(isEmpty()) return;

    Node<T>* temp = head;
    while(temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;
}

// Helper function to print list recursively starting from given node
template <class T>
void SinglyLinkedList<T>::printRecursiveHelper(Node<T>* current) const {
    if(isEmpty()) return;

    if (current == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }

    std::cout << current->data << " -> ";
    printRecursiveHelper(current->next);
}

// Public function to print list recursively starting from head
template <class T>
void SinglyLinkedList<T>::printRecursive() const {
    printRecursiveHelper(head);
    std::cout << std::endl;
}

template <class T>
void SinglyLinkedList<T>::removeAdjacentDuplicates() {
    if (isEmpty() || head->next == nullptr) {
        std::cout << "The list is empty. No duplicates to remove." << std::endl;
        return;
    }

    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr) {
        // if the current node's data is equal to the next node's data
        if (current->data == current->next->data) { 
            Node<T>* temp = current->next; // temporarily store the duplicate node
            current->next = current->next->next; // skip the duplicate node
            delete temp; // free the duplicate node's memory
            count--;
        } else {
            current = current->next; // move to the next node if no duplicate
        }
    }
}

template <class T>
void SinglyLinkedList<T>::sort() {
    if (isEmpty() || head->next == nullptr) {
        std::cout << "The list is empty or contains only one node. Sorting is not required." << std::endl;
        return;
    }

    bool swapped;

    do {
        swapped = false;
        Node<T>* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            } else {
                current = current->next;
            }
        }

    } while (swapped);
}
