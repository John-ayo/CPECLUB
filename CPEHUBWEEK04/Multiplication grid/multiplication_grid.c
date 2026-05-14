#include <stdio.h>
 
int main() {
    int size;
    printf("   CPE Hub - Dynamic Multiplication Grid\n");
 
    // INPUT VALIDATION - matches the spec requirement
    do {
        printf("Enter grid size (must be greater than 0): ");
        scanf("%d", &size);
 
        if (size <= 0) {
            printf("Invalid input. Grid size must be greater than 0.\n\n");
        }
    } while (size <= 0);
 
    printf("\n");
 
    // HEADER ROW
    // Print column labels: "Col 1", "Col 2", ..., "Col N"
    // Each label uses 8 characters of width to stay aligned
    // with the data rows below it.
    printf("        "); // leading space to align with row labels
    for (int col = 1; col <= size; col++) {
        printf(" Col %-3d", col);
    }
    printf("\n");
 
    // Print a separator line for readability //
    printf("        ");
    for (int col = 1; col <= size; col++) {
        printf("--------");
    }
    printf("\n");
 
    // OUTER LOOP = rows (O(n) iterations)
    // INNER LOOP = columns (O(n) iterations per row)
    // Together: O(n^2) total operations
    // From Grokking Ch.1: this is the "draw 16 boxes one at a time" approach.
    // There's no shortcut here - every cell must be computed and printed.
    // The math is just: result = row * col
    for (int row = 1; row <= size; row++) {
        printf("Row %-3d |", row); // row label, left-aligned in 3 chars
 
        for (int col = 1; col <= size; col++) {
            printf("   %4d ", row * col);
        }
 
        printf("\n"); // newline AFTER the inner loop completes a full row
    }
 
    printf("\n");
    printf("Grid size: %d x %d | Total cells computed: %d\n", size, size, size * size);
    printf("Time complexity: O(n^2) where n = %d\n", size);
    printf("\nDone.\n");
 
    return 0;
}