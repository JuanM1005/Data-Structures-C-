#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::reverse

/*
    Aguirre Mares Juan Antonio - Ingenieria Informatica
    Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)
    Universidad de Guadalajara
    31/08/2025
*/

int main() {
    // =============================
    // Create a vector
    // =============================
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // =============================
    // Access elements
    // =============================
    std::cout << "Element at index 2: " << numbers[2] << std::endl;
    std::cout << "Element at index 3 (using at): " << numbers.at(3) << std::endl;

    // =============================
    // Modify elements
    // =============================
    numbers[1] = 25;
    std::cout << "Modified element at index 1: " << numbers[1] << std::endl;

    // =============================
    // Add elements
    // =============================
    numbers.push_back(60);
    std::cout << "Added 60 at the end of the vector." << std::endl;

    numbers.insert(numbers.begin() + 2, 15);
    std::cout << "Inserted 15 at position 2." << std::endl;

    // =============================
    // Remove elements
    // =============================
    numbers.pop_back();
    std::cout << "Removed the last element." << std::endl;

    numbers.erase(numbers.begin() + 1);
    std::cout << "Removed element at position 1." << std::endl;

    // =============================
    // Iterate over the vector
    // =============================
    std::cout << "Vector elements (classic for loop): ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector elements (for-each loop): ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector elements (using iterators): ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // =============================
    // Other useful operations
    // =============================
    std::cout << "Vector size: " << numbers.size() << std::endl;
    std::cout << "Is vector empty? " << (numbers.empty() ? "Yes" : "No") << std::endl;

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Vector sorted ascending: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    std::sort(numbers.rbegin(), numbers.rend());
    std::cout << "Vector sorted descending: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Vector reversed: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    numbers.clear();
    std::cout << "Vector after clear(), size: " << numbers.size() << std::endl;

    return 0;
}
