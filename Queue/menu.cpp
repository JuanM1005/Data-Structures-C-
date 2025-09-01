#include <iostream>
#include "Queue.cpp"

using namespace std;

void menu(Queue& q) {
    int choice = 0, value = 0;

    while(true) {
        cout << "=== QUEUE ===" << endl
             << "1. Enqueue" << endl
             << "2. Dequeue" << endl
             << "3. Size" << endl
             << "4. Front" << endl
             << "5. Rear" << endl
             << "6. Display" << endl
             << "7. Display in dequeue" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                try {
                    q.enqueue(value);
                } catch (const std::overflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try {
                    q.dequeue();
                } catch (const std::underflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                cout << "Number of elements in queue: " 
                     << (q.isEmpty() ? 0 : q.getRear() - q.getFront() + 1) << endl;
                break;
            case 4:
                try {
                    cout << "Front element: " << q.getFront() << endl;
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try {
                    cout << "Rear element: " << q.getRear() << endl;
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                q.display();
                break;
            case 7:
                q.display_indeuqeue();
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }
}
