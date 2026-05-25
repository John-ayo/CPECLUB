# Cramer's Rule: 2x2 Linear Equation Solver

## What it does
Takes six values from the user and calculates the values of x and y in this format:
```
ax + by = e
cx + dy = f
```

## How it works
- User inputs a, b, c, d, e, f
- Program calculates the main determinant: D = (a * d) - (b * c)
- If D equals 0, it prints: No unique solution.
- If D is valid, it calculates: Dx = (e * d) - (b * f), Dy = (a * f) - (e * c)
- Solves and prints: x = Dx / D, y = Dy / D

## If D = 0 the program catches it and exits cleanly without crashing
