# CPE Club - Projects

C and Python programs built as part of the CPE Club's hands-on programming sessions. Each week introduces new concepts, from core fundamentals to data structures, memory manipulation, algorithms, and file I/O.

---

## Projects Overview

| Week | Project | Language | Description |
|---|---|---|---|
| Week 1 | Cramer's Rule Solver | C | Solves a 2x2 system of linear equations |
| Week 1 | Mini Calculator | C | Performs basic arithmetic operations |
| Week 1 | Even/Odd Checker | C | Classifies a number as even or odd |
| Week 2 | Mini Firewall | C | Filters and orders network packets by priority |
| Week 2 | Shell-Based Phonebook | C | Manages a contact database using structs and pointers |
| Week 2 | Substitution Cipher Tool | C | Encrypts and decrypts messages using ASCII shifting |
| Week 4 | Dynamic Multiplication Grid | C | Generates a perfectly aligned n x n multiplication table |
| Week 4 | Student Information Management System | C | Full CRUD student records system with file I/O |
| Week 5 | Number Guessing Game | Python | Terminal guessing game with attempt tracking |

---

## What you will need
- GCC 14.3.0 installed and added to PATH
- Python 3 installed and added to PATH
- VS Code with the C/C++ extension by Microsoft
- Code::Blocks (for Week 1 projects)

---

## How to run Week 1 projects
1. Open Code::Blocks
2. Create a new Console Application in C
3. Paste the project code into main.c
4. Press F9 to compile and run
5. Follow the prompts on screen

## How to run Week 2, 4 projects
1. Open VS Code
2. Open the terminal with Ctrl + `
3. Compile the file:
```bash
gcc filename.c -o filename
```
4. Run it:
```bash
./filename
```

## How to run Week 5 projects
1. Open VS Code
2. Open the terminal with Ctrl + `
3. Run the file:
```bash
python filename.py
```

---

# Week 1 Projects

## Project 1: Cramer's Rule Solver

Solves a 2x2 system of linear equations using Cramer's Rule.

### What it does
Takes six values from the user and calculates x and y in this format:
```
ax + by = e
cx + dy = f
```

### How it works
- User inputs a, b, c, d, e, f
- Calculates main determinant D = (a x d) - (b x c)
- If D = 0, prints an error and exits
- Otherwise calculates Dx, Dy, then solves for x and y

### Edge Case
If D = 0 the program catches it and exits cleanly without crashing.

---

## Project 2: Mini Calculator

Performs basic arithmetic between two numbers using an operator selected by the user.

### What it does
Takes two numbers and an operator then returns the result.

### Supported operators
```
+  addition
-  subtraction
*  multiplication
/  division
```

### Edge Cases
- Division by zero prints an error instead of crashing
- Invalid operator prints an error message

---

## Project 3: Even/Odd Checker

Classifies any whole number as either Even or Odd using the modulo operator.

### How it works
- User enters a whole number
- Program runs number % 2
- If remainder is 0 it prints Even, otherwise it prints Odd

---

## Concepts covered in Week 1

| Concept | Where it appears |
|---|---|
| User input | All three projects |
| Conditionals (if/else) | All three projects |
| Data types (int, double, char) | All three projects |
| Modulo operator | Even/Odd Checker |
| Determinants | Cramer's Rule Solver |
| Edge case handling | Calculator and Cramer's Rule |
| Format specifier %.2f | Calculator and Cramer's Rule |

---

# Week 2 Projects

## Project 1: Mini Firewall (Packet Filtering)

### Objective
A firewall that filters and orders network packets based on priority and sequence.

### How it works
- Reads 10 packets from a `packets.txt` file
- Each packet has a serial number and a priority (1 being highest, 10 being lowest)
- Outputs serial numbers ordered by highest priority, then by lowest serial number for ties

### How to run
```bash
gcc firewall.c -o firewall
./firewall
```

### Input format (packets.txt)
```
1, 5
10, 1
3, 2
7, 1
4, 3
```

### Output
```
Filtered Packet Order:
SerialNo: 7  | Priority: 1
SerialNo: 10 | Priority: 1
SerialNo: 3  | Priority: 2
SerialNo: 4  | Priority: 3
SerialNo: 1  | Priority: 5
```

---

## Project 2: Shell-Based Phonebook

### How it works
- Uses a Contact struct with fixed-size character arrays
- All functions receive a pointer to the contact instead of the full struct
- Supports adding, searching, deleting, and listing contacts

### How to run
```bash
gcc phonebook.c -o phonebook
./phonebook
```

### Features
- Add a contact
- Search by name
- Delete a contact
- List all contacts

---

## Project 3: Substitution Cipher Tool

### Objective
Encrypt and decrypt messages by shifting each character's ASCII value using a key.

### How it works
- Accepts a string and an integer key
- Uses a pointer to walk through the string in memory
- Shifts each character's ASCII value by the key to encrypt or reverse it to decrypt

### How to run
```bash
gcc ciphertool.c -o ciphertool
./ciphertool
```

### Example
```
Choice: 1
Enter message: hello
Enter key: 3
Encrypted: khoor

Choice: 2
Enter message: khoor
Enter key: 3
Decrypted: hello
```

---

## Concepts covered in Week 2

| Concept | Where it appears |
|---|---|
| Structs | Mini Firewall and Phonebook |
| Pointers | All three projects |
| File I/O | Mini Firewall |
| Memory manipulation | Phonebook and Cipher Tool |
| Sorting algorithms (qsort) | Mini Firewall |
| ASCII shifting | Substitution Cipher Tool |
| Null terminator handling | Phonebook and Cipher Tool |

---

# Week 4 Projects

## Project 1: Dynamic Multiplication Grid

### Objective
A terminal program that takes a grid size from the user and generates a perfectly aligned n x n multiplication table.

### How it works
- Prompts the user for a grid size and validates that it is greater than zero
- Uses nested loops to compute and print every cell value
- Formats output with aligned column and row labels
- Displays total cells computed and the time complexity at the end

### Algorithm
This program applies **O(n²) nested iteration** from Big O notation.
- Outer loop handles rows: O(n)
- Inner loop handles columns: O(n) per row
- Combined: O(n²) total operations

Reference: *Grokking Algorithms, 2nd Edition* by Aditya Bhargava, Chapter 1.

### How to run
```bash
gcc multiplication_grid.c -o multiplication_grid
./multiplication_grid
```

### Sample output
```
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

## Project 2: Student Information Management System (SIMS)

### Objective
A terminal-based student records system that supports full CRUD operations, bulk file import, and file export.

### How it works
- Stores all records in a fixed-size array of structs (up to 100 students)
- Each record holds first name, last name, roll number, CGPA, and five course IDs
- Searches use linear search (O(n)) since records are added and deleted freely
- Deleting a record shifts all subsequent elements one position back in the array

### Algorithm design

| Operation | Algorithm | Time Complexity |
|---|---|---|
| Add student | Array insert at end | O(1) |
| Find by roll / name | Linear search | O(n) |
| Delete student | Array shift-left | O(n) |
| Update student | Linear search + in-place edit | O(n) |
| Bulk import | Sequential file read | O(n) |
| Export all | Sequential array scan | O(n) |

Reference: *Grokking Algorithms, 2nd Edition* by Aditya Bhargava, Chapters 1 and 2.

### How to run
```bash
gcc sims.c -o sims
./sims
```

Place `students.txt` in the same folder as the executable before using the Bulk Import option.

### Text file format (students.txt)
```
FirstName LastName RollNumber CGPA Course1 Course2 Course3 Course4 Course5
```

Sample:
```
Billo Doe 101 4.2 10 11 12 13 14
Amara Smith 102 4.8 10 15 16 17 18
Emmanuel Okon 103 3.9 11 12 19 20 21
Precious Nnamdi 104 4.5 10 13 14 22 23
```

### Menu options

| Option | Action |
|---|---|
| 1 | Add Student Details (Manual Input) |
| 2 | Bulk Import Students (Read from students.txt) |
| 3 | Download All Students (Write to database_backup.txt) |
| 4 | Find Student by Roll Number |
| 5 | Find Student by First Name |
| 6 | Delete Student by Roll Number |
| 7 | Update Student by Roll Number |
| 8 | Display All Students in Memory |
| 9 | Exit |

---

## Concepts covered in Week 4

| Concept | Where it appears |
|---|---|
| Nested loops | Multiplication Grid |
| Big O notation (O(n²)) | Multiplication Grid |
| Output formatting with %d width | Multiplication Grid |
| Structs and arrays of structs | SIMS |
| Linear search | SIMS |
| Array deletion with element shifting | SIMS |
| File I/O (fscanf, fprintf) | SIMS |
| Input validation | Both projects |
| Duplicate detection | SIMS |
| Menu-driven flow with switch | SIMS |

---

# Week 5 Projects

## Project 1: Number Guessing Game

A terminal game where the computer holds a hidden number and the player guesses until they get it right.

### How it works
- A hidden number is set between 1 and 20
- Player keeps guessing until they match it
- Program tells them if each guess is too high or too low
- Attempt count is tracked and shown when the player wins

### How to run
```bash
python guessing_game.py
```

### Example output
```
Guess a number between 1 and 20: 15
Too high! Try again.
Guess a number between 1 and 20: 5
Too low! Try again.
Guess a number between 1 and 20: 7
Congratulations! You guessed the number in 3 tries!
```

---

## Concepts covered in Week 5

| Concept | Where it appears |
|---|---|
| Variables and data types | Guessing Game |
| While loops | Guessing Game |
| Conditionals (if, elif, else) | Guessing Game |
| Type conversion with int() | Guessing Game |
| Attempt counter | Guessing Game |

---

## Tech Stack
- Language: C, Python
- Compiler: GCC 14.3.0
- Python: 3.x
- OS: Windows 11

## Author
John-ayo - CPEClub Week 1, Week 2, Week 4, and Week 5