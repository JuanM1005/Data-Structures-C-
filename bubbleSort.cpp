#include <iostream>
#include <utility>

using namespace std;

// Function prototypes
void display(int arr[], int n);
void bubbleSort(int arr[], int n);

int main() {
    int arr[] = {2, 45, 0, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    bubbleSort(arr, n);

    cout << "\nSorted array: ";
    display(arr, n);

    return 0;
}

// Function to display array elements
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Bubble sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, array is sorted
        if (!swapped) break;
    }
}
