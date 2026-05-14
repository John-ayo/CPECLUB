# Dynamic Multiplication Grid

**CPE Hub - Week 04 Project**

A terminal-based C program that takes a grid size from the user and generates a perfectly aligned multiplication table of that exact size.

---

## What It Does

- Prompts the user to enter a grid size
- Validates that the input is greater than zero
- Generates a formatted n x n multiplication table
- Displays row and column labels for readability
- Shows the total cells computed and the time complexity

---

## Algorithm

This program uses **nested iteration**, which has a time complexity of **O(n²)**.

- The outer loop handles rows: O(n) iterations
- The inner loop handles columns: O(n) iterations per row
- Together: O(n * n) = O(n²) total operations

For example:
- Grid size 5 = 25 operations
- Grid size 10 = 100 operations
- Grid size 20 = 400 operations

Reference: *Grokking Algorithms, 2nd Edition* by Aditya Bhargava, Chapter 1 (Big O Notation).

---

## Sample Output

```
=========================================
   CPE Hub - Dynamic Multiplication Grid
=========================================

Enter grid size (must be greater than 0): 5

          Col 1   Col 2   Col 3   Col 4   Col 5
        ----------------------------------------
Row 1   |      1       2       3       4       5
Row 2   |      2       4       6       8      10
Row 3   |      3       6       9      12      15
Row 4   |      4       8      12      16      20
Row 5   |      5      10      15      20      25

Grid size: 5 x 5 | Total cells computed: 25
Time complexity: O(n^2) where n = 5
```

---

## How to Compile and Run

Make sure GCC is installed on your machine.

```bash
gcc multiplication_grid.c -o multiplication_grid
./multiplication_grid
```

On Windows:
```bash
gcc multiplication_grid.c -o multiplication_grid
multiplication_grid.exe
```

---

## Concepts Covered

- Input handling and validation with `scanf()`
- Nested `for` loops
- Output formatting with `%d` width specifiers
- Big O notation in practice (O(n²))

---

## Author

John Ayo - Computer Engineering Student, CPE Hub Week 04