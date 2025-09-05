#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;

void menu() {
    SinglyLinkedList<int> list;
    int option;
    int value, position;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Remove at beginning\n";
        cout << "5. Remove at end\n";
        cout << "6. Remove at position\n";
        cout << "7. Remove by value\n";
        cout << "8. Print list\n";
        cout << "9. Print list recursively\n";
        cout << "10. Get value at position\n";
        cout << "11. Check if value exists\n";
        cout << "12. Get size\n";
        cout << "13. Clear list\n";
        cout << "14. Remove adjacent duplicates (requires sorted list)\n";
        cout << "15. Sort elements\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Enter value to insert at beginning: ";
                    cin >> value;
                    list.insertAtBeginning(value);
                    break;
                case 2:
                    cout << "Enter value to insert at end: ";
                    cin >> value;
                    list.insertAtEnd(value);
                    break;
                case 3:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter position (0-based): ";
                    cin >> position;
                    list.insertAtPosition(value, position);
                    break;
                case 4:
                    list.removeAtBeggining();
                    cout << "Removed element at beginning.\n";
                    break;
                case 5:
                    list.removeAtEnd();
                    cout << "Removed element at end.\n";
                    break;
                case 6:
                    cout << "Enter position to remove (0-based): ";
                    cin >> position;
                    list.removeAtPosition(position);
                    cout << "Removed element at position " << position << ".\n";
                    break;
                case 7:
                    cout << "Enter value to remove: ";
                    cin >> value;
                    if (list.remove(value)) {
                        cout << "Successfully removed value " << value << ".\n";
                    } else {
                        cout << "Value " << value << " not found in the list.\n";
                    }
                    break;
                case 8:
                    cout << "List contents:\n";
                    list.print();
                    break;
                case 9:
                    cout << "List contents (recursive):\n";
                    list.printRecursive();
                    break;
                case 10:
                    cout << "Enter position to get value (0-based): ";
                    cin >> position;
                    cout << "Value at position " << position << ": " << list.getAt(position) << endl;
                    break;
                case 11:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (list.contains(value))
                        cout << "Value found.\n";
                    else
                        cout << "Value not found.\n";
                    break;
                case 12:
                    cout << "List size: " << list.size() << endl;
                    break;
                case 13:
                    list.clear();
                    cout << "List cleared.\n";
                    break;
                case 14:
                    cout << "Sorting the list automatically before removing duplicates..." << endl;
                    list.sort();
                    list.removeAdjacentDuplicates();
                    list.print();
                    break;
                case 15:
                    list.sort();
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
