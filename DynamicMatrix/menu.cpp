#include <iostream>
#include "DynamicMatrix.cpp"

using namespace std;

void menu() {
    DynamicMatrix dm;
    int option = -1;
    bool matrixAllocated = false;

    do {
        cout << "\n--- Dynamic Matrix Menu ---\n";
        cout << "1. Set matrix dimensions\n";
        cout << "2. Fill matrix\n";
        cout << "3. Display matrix\n";
        cout << "4. Free matrix memory\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        try {
            switch (option) {
                case 1:
                    dm.requestDimensions();
                    dm.allocateMatrix();
                    matrixAllocated = true;
                    break;
                case 2:
                    if (!matrixAllocated) {
                        cout << "Error: Please set dimensions and allocate matrix first.\n";
                    } else {
                        dm.fillMatrix();
                    }
                    break;
                case 3:
                    if (!matrixAllocated) {
                        cout << "Error: No matrix allocated to display.\n";
                    } else {
                        dm.displayMatrix();
                    }
                    break;
                case 4:
                    if (!matrixAllocated) {
                        cout << "Matrix is not allocated.\n";
                    } else {
                        dm.freeMatrixMemory();
                        matrixAllocated = false;
                        cout << "Matrix memory freed.\n";
                    }
                    break;
                case 0:
                    cout << "Exiting program.\n";
                    break;
                default:
                    cout << "Invalid option. Try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (option != 0);
}
