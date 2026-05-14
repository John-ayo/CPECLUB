# Student Information Management System (SIMS)

**CPE Hub - Week 04 Project**

A terminal-based C program that manages student records with full CRUD operations, file import, and file export support.

---

## What It Does

- Add student records manually
- Bulk import students from a `.txt` file
- Export all records to a backup `.txt` file
- Search for students by roll number or first name
- Update existing student records
- Delete student records
- All data is held in memory using a fixed-size array of structs

---

## Data Structure

Each student record uses the following struct:

```c
struct sinfo {
    char fname[50];
    char lname[50];
    int  roll;
    float cgpa;
    int  cid[5];
};
```

A fixed-size array (`MAX_STUDENTS = 100`) stores all records in memory.

---

## Algorithm Design

All algorithms reference *Grokking Algorithms, 2nd Edition* by Aditya Bhargava.

| Operation | Algorithm | Time Complexity | Reference |
|---|---|---|---|
| Add student | Array insert at end | O(1) | Chapter 2 |
| Find by roll / name | Linear (simple) search | O(n) | Chapter 1 |
| Delete student | Array shift-left | O(n) | Chapter 2 |
| Update student | Linear search + in-place edit | O(n) | Chapter 1-2 |
| Bulk import | Sequential file read | O(n) | Chapter 2 |
| Export all | Sequential array scan | O(n) | Chapter 2 |

**Why linear search over binary search?**
Binary search is O(log n) but requires a sorted array. Since records are added and deleted freely, maintaining a sorted order would add overhead on every write. Linear search is the correct tradeoff for this system.

**Why an array over a linked list?**
Arrays provide O(1) direct access by index. For a system that reads and searches frequently, arrays win over linked lists which have slower reads.

---

## Text File Format

The `students.txt` import file must follow this exact space-separated format:

```
FirstName LastName RollNumber CGPA Course1 Course2 Course3 Course4 Course5
```

Sample `students.txt`:
```
Billo Doe 101 4.2 10 11 12 13 14
Amara Smith 102 4.8 10 15 16 17 18
Emmanuel Okon 103 3.9 11 12 19 20 21
Precious Nnamdi 104 4.5 10 13 14 22 23
```

Place this file in the same directory as the compiled executable before running option 2.

---

## Menu Options

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

## How to Compile and Run

Make sure GCC is installed on your machine.

```bash
gcc sims.c -o sims
./sims
```

On Windows:
```bash
gcc sims.c -o sims
sims.exe
```

Make sure `students.txt` is in the same folder as the executable before using the Bulk Import option.

---

## Concepts Covered

- Structs and arrays of structs
- File I/O with `fopen`, `fscanf`, `fprintf`, `fclose`
- Linear search (simple search)
- Array deletion with element shifting
- Input validation and duplicate detection
- Menu-driven program flow with `switch` statements

---

## Author

John Ayo - Computer Engineering Student, CPE Hub Week 04