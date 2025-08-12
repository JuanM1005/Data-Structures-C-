#include <iostream>
#include "LinkedQueue.cpp"

using namespace std;

void menu() {
    LinkedQueue<int> queue;
    int option;
    int value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get front\n";
        cout << "4. Get rear\n";
        cout << "5. Check if queue is empty\n";
        cout << "6. Get queue size\n";
        cout << "7. Print queue\n";
        cout << "8. Print queue recursively\n";
        cout << "9. Clear queue\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    queue.enqueue(value);
                    break;
                case 2:
                    queue.dequeue();
                    cout << "Dequeued element.\n";
                    break;
                case 3:
                    cout << "Front element: " << queue.getFront() << endl;
                    break;
                case 4:
                    cout << "Rear element: " << queue.getRear() << endl;
                    break;
                case 5:
                    if (queue.isEmpty())
                        cout << "Queue is empty.\n";
                    else
                        cout << "Queue is not empty.\n";
                    break;
                case 6:
                    cout << "Queue size: " << queue.size() << endl;
                    break;
                case 7:
                    cout << "Queue contents: ";
                    queue.print();
                    break;
                case 8:
                    cout << "Queue contents (recursive): ";
                    queue.printRecursive();
                    break;
                case 9:
                    queue.clear();
                    cout << "Queue cleared.\n";
                    break;
                case 0:
                    cout << "Goodbye!\n";
                    break;
                default:
                    cout << "Invalid option. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (option != 0);
}