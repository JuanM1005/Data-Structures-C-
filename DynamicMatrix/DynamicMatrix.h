#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H

#include <iostream>
#include <stdexcept>

using namespace std;

// Class to handle a dynamic 2D integer matrix
class DynamicMatrix {
    private:
        int** matrix;    // Pointer to the matrix (array of int pointers)
        int numRows;     // Number of rows
        int numCols;     // Number of columns

    public:
        DynamicMatrix();   // Constructor
        ~DynamicMatrix();  // Destructor

        // Requests matrix dimensions from user and validates input
        void requestDimensions();

        // Allocates memory dynamically for the matrix based on dimensions
        void allocateMatrix();

        // Fills the matrix with user input values
        void fillMatrix();

        // Displays the matrix contents on the console
        void displayMatrix() const;

        // Frees dynamically allocated memory to prevent memory leaks
        void freeMatrixMemory();
};

#endif
