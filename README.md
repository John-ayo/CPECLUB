# CPE Club - Projects

C programs built as part of the CPE Club's first two weeks of hands-on programming. Week 1 covers core programming fundamentals while Week 2 dives into data structures, memory manipulation, and pointers.

---

## Projects Overview

| Week | Project | Description |
|---|---|---|
| Week 1 | Cramer's Rule Solver | Solves a 2x2 system of linear equations |
| Week 1 | Mini Calculator | Performs basic arithmetic operations |
| Week 1 | Even/Odd Checker | Classifies a number as even or odd |
| Week 2 | Mini Firewall | Filters and orders network packets by priority |
| Week 2 | Shell-Based Phonebook | Manages a contact database using structs and pointers |
| Week 2 | Substitution Cipher Tool | Encrypts and decrypts messages using ASCII shifting |

---

## What you will need
- GCC 14.3.0 installed and added to PATH
- VS Code with the C/C++ extension by Microsoft
- Code::Blocks (for Week 1 projects)

---

## How to run Week 1 projects
1. Open Code::Blocks
2. Create a new Console Application in C
3. Paste the project code into main.c
4. Press F9 to compile and run
5. Follow the prompts on screen

## How to run Week 2 projects
1. Open VS Code
2. Open the terminal with Ctrl + 
3. Compile the file:
``bash
gcc filename.c -o filename
4. Run it:
bash
./filename

---

# Week 1 Projects

## Project 1: Cramer's Rule Solver

Solves a 2x2 system of linear equations using Cramer's Rule.

### What it does
Takes six values from the user and calculates x and y in this format:
ax + by = e
cx + dy = f

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
+  addition
-  subtraction
*  multiplication
/  division

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
bash
gcc firewall.c -o firewall
./firewall

### Input format (packets.txt)
1, 5
10, 1
3, 2
7, 1
4, 3

### Output
Filtered Packet Order:
SerialNo: 7  | Priority: 1
SerialNo: 10 | Priority: 1
SerialNo: 3  | Priority: 2
SerialNo: 4  | Priority: 3
SerialNo: 1  | Priority: 5

---

## Project 2: Shell-Based Phonebook

### How it works
- Uses a Contact struct with fixed-size character arrays
- All functions receive a pointer to the contact instead of the full struct
- Supports adding, searching, deleting, and listing contacts

### How to run
bash
gcc phonebook.c -o phonebook
./phonebook
`
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
gcc ciphertool.c -o ciphertool
./cipher
### Example
Choice: 1
Enter message: hello
Enter key: 3
Encrypted: khoor

Choice: 2
Enter message: khoor
Enter key: 3
Decrypted: hello
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

## Tech Stack
- Language: C
- Compiler: GCC 14.3.0
- OS: Windows 11

## Author
Johnpaul3.0 - CPE Club Week 1 and Week 2
