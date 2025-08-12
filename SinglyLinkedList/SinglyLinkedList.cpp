#include "SinglyLinkedList.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), count(0) {}
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <class T>
void SinglyLinkedList<T>::insertAtBeggining(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    count++;
}

template <class T>
void SinglyLinkedList<T>::insertAtEnd(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if(isEmpty()) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        count++;
    }
}

template <class T>
void SinglyLinkedList<T>::insertAtPosition(const T& value, int position) {
    if(position < 0 || position > count) {
        throw std::out_of_range("Index out of range");
    }

    if(position == 0) {
        insertAtBeggining(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    for(int i = 1; i < position; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next; 
    temp->next = newNode;
    count++;
}


template <class T>
void SinglyLinkedList<T>::removeAtBeggining() {
    if(isEmpty()) return;

    Node<T>* temp = head;
    head = head->next;
    delete temp;
    count--;
}

template <class T>
void SinglyLinkedList<T>::removeAtEnd() {
    if(isEmpty()) return;

    if(head->next == nullptr) { // Si solo es un elemento
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head;
        while(temp->next->next != nullptr) { // Recorremos al llegar al penultimo nodo
            temp = temp->next;
        }

        delete temp->next; // Elimina el ultimo nodo
        temp->next = nullptr;
    }

    count--;
}

template <class T>
void SinglyLinkedList<T>::removeAtPosition(int position) {
    if (position < 1 || position > count) {
        throw std::out_of_range("Invalid position");
    }

    if (position == 1) {
        removeAtBeggining();
        return;
    }

    Node<T>* current = head;
    for(int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    Node<T>* temp = current->next; // Guarda el nodo a eliminar
    current->next = temp->next;
    delete temp;
    count--;
}

template <class T>
void SinglyLinkedList<T>::remove(const T& value) {
    // Si la lista está vacía, no hay nada que eliminar
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    // Si el valor a eliminar está en el primer nodo (head)
    if (head->data == value) {
        removeAtBeggining();
        return;
    }

    // Buscar el nodo que contiene el valor
    Node<T>* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    // Si encontramos el nodo con el valor, lo eliminamos
    if (current->next != nullptr) {
        Node<T>* temp = current->next;   // Nodo a eliminar
        current->next = current->next->next;  // Reconectar el nodo anterior al siguiente del nodo eliminado
        delete temp;  // Liberar la memoria del nodo eliminado
        count--;  // Reducir el tamaño de la lista
    } else {
        throw std::runtime_error("Value not found in the list");
    }
}

template <class T>
bool SinglyLinkedList<T>::contains(const T& value) {
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

template <class T>
bool SinglyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
int SinglyLinkedList<T>::size() const {
    return count;
}

template <class T>
T SinglyLinkedList<T>::getAt(int position) const {
    if(position < 0 || position > count) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* temp = head;
    for(int i = 0; i < position; i++) {
        temp = temp->next;
    }

    return temp->data;
}

template <class T>
void SinglyLinkedList<T>::clear() {
    while(!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    count = 0;
}

template <class T>
void SinglyLinkedList<T>::print() {
    if(isEmpty()) return;

    Node<T>* temp = head;
    while(temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;
}

template <class T>
void SinglyLinkedList<T>::printRecursiveHelper(Node<T>* current) {
    if(isEmpty()) return;
    
    if (current == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }

    std::cout << current->data << " -> ";
    printRecursiveHelper(current->next);
}

template <class T>
void SinglyLinkedList<T>::printRecursive() {
    printRecursiveHelper(head);
    std::cout << std::endl;
}