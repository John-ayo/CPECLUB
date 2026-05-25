#include <stdio.h>

int main() {
    int number;

    printf("=== Even/Odd Checker ===\n\n");
    printf("Enter a whole number: ");
    scanf("%d", &number);

    if(number % 2 == 0) {
        printf("\n%d is Even\n", number);
    } else {
        printf("\n%d is Odd\n", number);
    }

    return 0;
}
