# CPE Club - Week 1 Projects
 
Three beginner C programs built as part of the CPE Club's first week of hands-on programming. Each project was designed to practice core programming concepts like conditionals, variables, user input and data types.
 
---
 
## Projects Overview
 
| Project | Description |
|---|---|
| Cramer's Rule Solver | Solves a 2x2 system of linear equations |
| Mini Calculator | Performs basic arithmetic operations |
| Even/Odd Checker | Classifies a number as even or odd |
 
---
 
## What you will need
- Code::Blocks installed on your machine
- GCC GNU Compiler set as default in Code::Blocks
---
 
## How to run any project
1. Open Code::Blocks
2. Create a new Console Application in C
3. Paste the project code into main.c
4. Press F9 to compile and run
5. Follow the prompts on screen
---
 
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
 
## Concepts covered across all three projects
 
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
 
## Author
Johnpaull3.0 - CPEClub Week 1
