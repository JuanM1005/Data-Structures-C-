#include <iostream>
#include "Queue.cpp"

void menu() {
    // Create a queue of integers with a max size of 10 for testing
    Queue<int, 10> q;
    int choice = 0, value = 0;

    while(true) {
        std::cout << "\n--- Array-based Circular Queue Menu ---\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. Get Front Element\n"
                  << "4. Get Rear Element\n"
                  << "5. Get Size\n"
                  << "6. Display Queue\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        
        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        try {
            switch(choice) {
                case 1:
                    std::cout << "Enter value to enqueue: ";
                    std::cin >> value;
                    q.enqueue(value);
                    std::cout << value << " enqueued successfully.\n";
                    break;
                case 2:
                    q.dequeue();
                    std::cout << "Dequeued successfully.\n";
                    break;
                case 3:
                    std::cout << "Front element: " << q.getFront() << std::endl;
                    break;
                case 4:
                    std::cout << "Rear element: " << q.getRear() << std::endl;
                    break;
                case 5:
                    std::cout << "Number of elements in queue: " << q.size() << std::endl;
                    break;
                case 6:
                    q.display();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Invalid choice. Try again!" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
