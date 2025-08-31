#include <iostream>
#include "Stack.cpp"

/*
    Aguirre Mares Juan Antonio - Ingenieria Informatica
    Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)
    Universidad de Guadalajara
    30/08/2025
*/

void firstFill20(Stack& s);

int main() {
    Stack s;

    try {
        firstFill20(s);

        s.display(); // Output: 20...15...1

        std::cout << "Top element: " << s.top() << std::endl;

        s.pop();
        s.display(); // Output: 19...15...1

        s.pop();
        s.pop();
        s.pop(); // Output: 16...10...1
        
        std::cout << std::endl;
        s.display();

        std::cout << std::endl;
        s.display_inpop();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

void firstFill20(Stack& s) {
    for(int i = 1; i <= 20; i++) {
        if (s.isFull()) {
            std::cout << "Stack is full. Could not insert all 20 numbers." << std::endl;
            break;
        }

        s.push(i);
    }
}