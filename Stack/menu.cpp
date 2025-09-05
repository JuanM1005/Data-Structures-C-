#include <iostream>
#include "Stack.cpp"


void menu() {
    Stack<int, 20> s;
    int choice = 0, value = 0;

    while (true) {
        std::cout << "=== STACK ===" << std::endl
             << "1. Push" << std::endl
             << "2. Pop" << std::endl
             << "3. Size" << std::endl
             << "4. Top" << std::endl
             << "5. Display" << std::endl
             << "6. Display in pop" << std::endl
             << "0. Exit" << std::endl
             << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                try {
                    s.push(value);
                } catch (const std::overflow_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 2:
                try {
                    s.pop();
                } catch (const std::underflow_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "Number of elements in stack: " << s.size() << std::endl;
                break;
            case 4:
                try {
                    std::cout << "Top element: " << s.top() << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.display_inpop();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Try again!" << std::endl;
        }
        std::cout << std::endl;
    }
}
