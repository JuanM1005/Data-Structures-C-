#include <iostream>
#include "Queue.cpp"

/*
    Aguirre Mares Juan Antonio - Ingenieria Informatica
    Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)
    Universidad de Guadalajara
    30/08/2025
*/

int main() {
    Queue q;

    try {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.displayQueue(); // Queue: 10 20 30

        cout << "Front of the queue: " << q.getFront() << endl;

        q.dequeue();
        q.displayQueue(); // Queue: 20 30

        // Example of exception
        q.dequeue();
        q.dequeue();
        q.dequeue(); // This will throw an exception

    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
