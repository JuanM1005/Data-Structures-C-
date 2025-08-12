#include <iostream>
#include <utility>

using namespace std;

// Function prototypes
void display(int arr[], int n);
void selectionSort(int arr[], int n);

int main() {
    int numbers[] = {2, 6, 1, 52, 10};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original array: ";
    display(numbers, n);

    selectionSort(numbers, n);

    cout << "\nSorted array: ";
    display(numbers, n);

    return 0;
}

// Function to display array elements
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Selection sort implementation
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        bool swapped = false;

        // Find the minimum element in unsorted array
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
                swapped = true;
            }
        }

        // Swap the found minimum element with the first element
        if(swapped) {
            swap(arr[i], arr[minIndex]);
        } else {
            // If no swaps needed, array is sorted
            break;
        }
    }
}
