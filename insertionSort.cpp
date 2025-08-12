#include <iostream>

using namespace std;

// Function prototypes
void display(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    int arr[] = {2, 6, 1, 52, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    insertionSort(arr, n);

    cout << "\nSorted array: ";
    display(arr, n);

    return 0;
}

// Function to display array elements
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Insertion sort algorithm implementation
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];     // Current value to insert
        int j = i - 1;        // Index of previous element

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j--;                  // Move leftward to check next element
        }
        arr[j + 1] = key;  // Insert key in correct position
    }
}
