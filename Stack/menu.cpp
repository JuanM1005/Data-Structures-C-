#include <iostream>
#include "Stack.cpp"

using namespace std;

void menu(Stack& s) {
    int choice = 0, value = 0;

    while (true) {
        cout << "=== STACK ===" << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Size" << endl
             << "4. Top" << endl
             << "5. Display" << endl
             << "6. Display in pop" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                try {
                    s.push(value);
                } catch (const std::overflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try {
                    s.pop();
                } catch (const std::underflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                cout << "Number of elements in stack: " << s.size() << endl;
                break;
            case 4:
                try {
                    cout << "Top element: " << s.top() << endl;
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
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
                cout << "Invalid choice. Try again!" << endl;
        }
        cout << endl;
    }
}
