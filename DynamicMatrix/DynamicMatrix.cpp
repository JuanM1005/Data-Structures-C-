#include "DynamicMatrix.h"

// Constructor initializes pointer and dimensions to safe defaults
DynamicMatrix::DynamicMatrix() : matrix(nullptr), numRows(0), numCols(0) {}

// Destructor frees memory when object goes out of scope
DynamicMatrix::~DynamicMatrix() {
    freeMatrixMemory();
}

// Request the number of rows and columns from the user, validate input
void DynamicMatrix::requestDimensions() {
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    if (numRows <= 0 || numCols <= 0) {
        throw runtime_error("Error: Number of rows and columns must be greater than 0.");
    }
}

// Allocate dynamic memory for the matrix based on rows and columns
void DynamicMatrix::allocateMatrix() {
    matrix = new int*[numRows];  // Allocate array of row pointers
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];  // Allocate each row
    }
}

// Fill matrix elements by prompting user input
void DynamicMatrix::fillMatrix() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Print the matrix in row-column format
void DynamicMatrix::displayMatrix() const {
    cout << "\nMatrix contents:\n";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Deallocate all dynamically allocated memory
void DynamicMatrix::freeMatrixMemory() {
    if (matrix != nullptr) {
        for (int i = 0; i < numRows; i++) {
            delete[] matrix[i];  // Delete each allocated row
        }
        delete[] matrix;  // Delete array of pointers
        matrix = nullptr; // Avoid dangling pointer
    }
}
