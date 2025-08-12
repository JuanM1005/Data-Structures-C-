#include <iostream>
#include "DynamicArray.cpp"

using namespace std;

void menu() {
    DynamicArray<int> arr;
    int option;
    int value, position;

    do {
        cout << "\n--- Dynamic Array Menu ---\n";
        cout << "1. Add at beginning\n";
        cout << "2. Add at end\n";
        cout << "3. Add at position\n";
        cout << "4. Remove from beginning\n";
        cout << "5. Remove from end\n";
        cout << "6. Remove from position\n";
        cout << "7. Search for value\n";
        cout << "8. Show array\n";
        cout << "9. Get value at position\n";
        cout << "10. Get size\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Enter value to add at beginning: ";
                    cin >> value;
                    arr.addAtBeginning(value);
                    break;
                case 2:
                    cout << "Enter value to add at end: ";
                    cin >> value;
                    arr.addAtEnd(value);
                    break;
                case 3:
                    cout << "Enter value to add: ";
                    cin >> value;
                    cout << "Enter position (0-based): ";
                    cin >> position;
                    arr.addAtPosition(value, position);
                    break;
                case 4:
                    arr.removeFromBeginning();
                    cout << "Removed element from beginning.\n";
                    break;
                case 5:
                    arr.removeFromEnd();
                    cout << "Removed element from end.\n";
                    break;
                case 6:
                    cout << "Enter position to remove (0-based): ";
                    cin >> position;
                    arr.removeFromPosition(position);
                    cout << "Removed element from position " << position << ".\n";
                    break;
                case 7:
                    cout << "Enter value to search: ";
                    cin >> value;
                    {
                        int* found = arr.search(value);
                        if (found)
                            cout << "Value found at address: " << found << endl;
                        else
                            cout << "Value not found.\n";
                    }
                    break;
                case 8:
                    cout << "Array contents:\n";
                    arr.display();
                    break;
                case 9:
                    cout << "Enter position to get value (0-based): ";
                    cin >> position;
                    cout << "Value at position " << position << ": " << arr[position] << endl;
                    break;
                case 10:
                    cout << "Array size: " << arr.size() << endl;
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