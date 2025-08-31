#include <iostream>
#include "Stack.cpp"

/*
    Aguirre Mares Juan Antonio - Ingenieria Informatica
    Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)
    Universidad de Guadalajara
    30/08/2025
*/

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        s.display(); // Output: 30 20 10

        std::cout << "Top element: " << s.top() << std::endl;

        s.pop();
        s.display(); // Output: 20 10

        s.pop();
        s.pop();
        s.pop(); // This will throw an exception
    }
    catch (const std::runtime_error& e) {
        // Catch runtime errors and display message
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
