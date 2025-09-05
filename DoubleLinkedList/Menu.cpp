#include <iostream>
#include "DoubleLinkedList.cpp"

using namespace std;

void menu() {
    DoubleLinkedList<int> list;
    int option, value, position;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at back\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at front\n";
        cout << "5. Delete at back\n";
        cout << "6. Delete at position\n";
        cout << "7. Get value at position\n";
        cout << "8. Display forward\n";
        cout << "9. Display backward\n";
        cout << "10. Check if empty\n";
        cout << "11. Get size\n";
        cout << "12. Clear list\n";
        cout << "13. Sort list\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at back: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;

                try {
                    list.insertAtPosition(value, position);
                    cout << "Inserted " << value << " at position " << position << ".\n";
                } catch(const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }

                break;
            case 4:
                list.removeAtBeginning();
                cout << "Deleted element at front.\n";
                break;
            case 5:
                list.removeAtEnd();
                cout << "Deleted element at back.\n";
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                try {
                    list.removeAtPosition(position);
                    cout << "Deleted element at position " << position << ".\n";
                } catch(const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 7:
                cout << "Enter position to get value: ";
                cin >> position;
                try {
                    cout << "Value at position " << position << " is " << list.getAt(position) << ".\n";
                } catch(const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 8:
                cout << "List forward: ";
                list.displayForward();
                break;
            case 9:
                cout << "List backward: ";
                list.displayBackward();
                break;
            case 10:
                if(list.isEmpty())
                    cout << "The list is empty.\n";
                else
                    cout << "The list is not empty.\n";
                break;
            case 11:
                cout << "Size of the list: " << list.size() << endl;
                break;
            case 12:
                list.clear();
                cout << "List cleared.\n";
                break;
            case 13:
                list.sort();
                cout << "List sorted.\n";
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while(option != 0);
}
