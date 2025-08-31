# C++ Data Structures & Sorting Algorithms

**Repository:** `cpp-core-dsa` *(Data Structures & Algorithms Fundamentals)*  

Minimalist implementations of essential data structures and sorting algorithms in C++. Ideal for learning and reference.

---

## 🏗️ **Data Structures**
| Name               | Description                          | Key Operations           |
|--------------------|--------------------------------------|--------------------------|
| `BinarySearchTree` | Balanced search tree                 | Insert, Delete, Search   |
| `DynamicMatrix`    | 2D resizable array                   | Row/Column operations    |
| `DynamicArray`     | Vector-like resizable array          | Push/Pop, Random access  |
| `SinglyLinkedList` | Linear node chain                    | Add/Remove at head/tail  |
| `LinkedQueue`      | FIFO implementation                  | Enqueue, Dequeue         |
| `Stack`            | LIFO implementation                  | Push, Pop, Top, Display         |
| `Queue`            | FIFO implementation                  | Enqueue, Dequeue, Front, Display|

## 🔄 **Sorting Algorithms**
| Name             | Time (Worst) | Stable? | In-Place? |
|------------------|-------------|---------|-----------|
| `BubbleSort`     | O(n²)       | ✅      | ✅        |
| `CocktailSort`   | O(n²)       | ✅      | ✅        |
| `InsertionSort`  | O(n²)       | ✅      | ✅        |
| `SelectionSort`  | O(n²)       | ❌      | ✅        |

---

## 🚀 **Usage**
1. Clone and compile any file:
   ```bash
   g++ -std=c++17 DataStructures/SinglyLinkedList.cpp -o sll
   ./sll
