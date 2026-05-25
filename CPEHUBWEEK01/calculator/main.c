#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("=== Mint Calculator ===\n\n");

    printf("Enter first number: "); scanf("%lf", &num1);
    printf("Enter operator (+, -, *, /): "); scanf(" %c", &operator);
    printf("Enter second number: "); scanf("%lf", &num2);

    if (operator == '+') {
        result = num1 + num2;
        printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
    } else if (operator == '-'){
        result = num1 - num2;
        printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
    } else if (operator == '*') {
        result = num1 * num2;
        printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
        } else {
            result = num1 / num2;
            printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
        }
    } else {
        printf("\nError: Invalid operator. Please use +,-,*, or /\n");
    }

    return 0;
}
