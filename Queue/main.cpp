#include <iostream>
#include "Queue.cpp"

/*
    Aguirre Mares Juan Antonio - Ingenieria Informatica
    Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)
    Universidad de Guadalajara
    30/08/2025
*/

void enqueueFirst20(Queue& q);

int main() {
    Queue q;

    try {
        
        enqueueFirst20(q);

        q.display(); // Queue: 1..10..20

        cout << "Front of the queue: " << q.getFront() << endl;

        q.dequeue();
        q.display(); // Queue: 2..10..20

        q.dequeue();
        q.dequeue();
        q.dequeue(); // 5..10..20
        
        std::cout << std::endl;
        q.display();

        std::cout << std::endl;
        q.display_indeuqeue();

    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

void enqueueFirst20(Queue& q) {
    for (int i = 1; i <= 20; i++) {
        if (q.isFull()) {
            std::cout << "Queue is full. Could not insert all 20 numbers." << std::endl;
            break;
        }
        q.enqueue(i);
    }
}