#include "DoubleLinkedList.h"

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(): head(nullptr), tail(nullptr), count(0) {}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    clear();
}

template <class T>
void DoubleLinkedList<T>::insertAtBeginning(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if(!head) {
        head = tail = newNode;
        
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    count++;
       
}

template <class T>
void DoubleLinkedList<T>::insertAtEnd(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if(!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;
}

template <class T>
void DoubleLinkedList<T>::insertAtPosition(const T& value, int position) {
    if(position < 0 || position > count) {
        throw std::out_of_range("Invalid position");
    }

    if(position == 0) {
        insertAtBeginning(value);
        return;
    }

    if(position == count) {
        insertAtEnd(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head;

    for(int i = 0; i < position; i++) {
        current = current->next;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    count++;
}


template <class T>
void DoubleLinkedList<T>::removeAtBeginning() {
    if (isEmpty()) {
        throw std::underflow_error("Cannot remove from empty list");
    }

    Node<T>* temp = head;

    if(head->next) {
        head = head->next;
        head->prev = nullptr;
    } else {
        head = tail = nullptr;
    }

    delete temp;
    count--;
}

template <class T>
void DoubleLinkedList<T>::removeAtEnd() {
    if (isEmpty()) {
        throw std::underflow_error("Cannot remove from empty list");
    }

    Node<T>* temp = tail;

    if(tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }

    delete temp;
    count--;
}

template <class T>
void DoubleLinkedList<T>::removeAtPosition(int position) {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Index out of range.");
    }

    if (position == 0) {
        removeAtBeginning();
        return;
    }

    if (position == count - 1) {
        removeAtEnd();
        return;
    }

    Node<T>* current;
    if (position < count / 2) {
        current = head;
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        current = tail;
        for(int i = count - 1 ; i > position; i--) {
            current = current->prev;
        }
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    count--;
}

template <class T>
T DoubleLinkedList<T>::getAt(int position) const {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Index out of range.");
    }

    Node<T>* current;
    if (position < count / 2) {
        // Transverse from head
        current = head;
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        // Transverse from tail
        current = tail;
        for(int i = count - 1 ; i > position; i--) {
            current = current->prev;
        }
    }

    return current->data;
}

template <class T>
void DoubleLinkedList<T>::displayForward() const {
    if (isEmpty()) return;

    Node<T>* temp = head;
    std::cout << "nullptr ";
    while (temp != nullptr) {
        std::cout << "<- " << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <class T>
void DoubleLinkedList<T>::displayBackward() const {
    if (isEmpty()) return;

    Node<T>* temp = tail;
    std::cout << "nullptr ";
    while (temp != nullptr) {
        std::cout << "<- " << temp->data << " -> ";
        temp = temp->prev;
    }
    std::cout << "nullptr" << std::endl;
}

template <class T>
bool DoubleLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
void DoubleLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
int DoubleLinkedList<T>::size() const {
    return count;
}

template <class T>
void DoubleLinkedList<T>::sort() {
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

template <class T>
bool DoubleLinkedList<T>::contains(const T& value) const {
    Node<T>* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == value) return True;
        temp = temp->next;
    }

    return false;
}

template <class T>
int DoubleLinkedList<T>::indexof(const T& value) const {
    Node<T>* temp = head;
    int pos = 0;

    while (temp != nullptr) {
        if(temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }

    return -1;
}