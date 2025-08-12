#include <iostream>
#include "BinarySearchTree.cpp"  // Make sure this header contains full method implementations

using namespace std;

void menu() {
    BinarySearchTree<int> tree;
    int option, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert a value\n";
        cout << "2. Remove a value\n";
        cout << "3. Search for a value\n";
        cout << "4. In-order traversal\n";
        cout << "5. Pre-order traversal\n";
        cout << "6. Post-order traversal\n";
        cout << "7. Find minimum value\n";
        cout << "8. Find maximum value\n";
        cout << "9. PrintTree\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    tree.insert(value);
                    break;
                case 2:
                    cout << "Enter value to remove: ";
                    cin >> value;
                    tree.remove(value);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (tree.search(value))
                        cout << "Value found.\n";
                    else
                        cout << "Value not found.\n";
                    break;
                case 4:
                    cout << "In-order traversal: ";
                    tree.inOrder();
                    cout << endl;
                    break;
                case 5:
                    cout << "Pre-order traversal: ";
                    tree.preOrder();
                    cout << endl;
                    break;
                case 6:
                    cout << "Post-order traversal: ";
                    tree.postOrder();
                    cout << endl;
                    break;
                case 7:
                    cout << "Minimum value: " << tree.findMin() << endl;
                    break;
                case 8:
                    cout << "Maximum value: " << tree.findMax() << endl;
                    break;
                case 9:
                    tree.printTree();
                    system("pause");
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
