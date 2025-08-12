#include <iostream>
#include <utility>

using namespace std;

// Function prototypes
void display(int arr[], int n);
void cocktailSort(int arr[], int n);

int main() {
    int arr[] = {2, 45, 0, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    cocktailSort(arr, n);

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

// Cocktail sort implementation (bidirectional bubble sort)
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Forward pass: move the largest element to the end
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // If nothing moved, array is sorted
        if (!swapped) break;

        --end; // Decrease the range from the end since last element is sorted

        swapped = false;

        // Backward pass: move the smallest element to the start
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start; // Increase the range from the start since first element is sorted
    }
}
