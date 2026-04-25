#include <stdio.h>

int main()
{
    double a, b, c, d, e, f;
    double D, Dx, Dy, x, y;

    printf("=== Cramer's Rule: 2*2 Linear Equation Solver ===\n\n");

    printf("Enter coefficients for equation 1 (ax + by = e):\n");
    printf(" a: "); scanf("%lf", &a);
    printf(" b: "); scanf("%lf", &b);
    printf(" e: "); scanf("%lf", &e);

    printf("\nEnter coefficients for equation 2 (cx = dy = f):\n");
    printf(" c: "); scanf("%lf", &c);
    printf(" d: "); scanf("%lf", &d);
    printf(" f: "); scanf("%lf", &f);

    D = (a * d) - (b * c);

    if (D == 0) {
        printf("\nNo unique solution. \n");
    } else {
        Dx = (e * d) - (b * f);
        Dy = (a * f) - (e * c);

        x = Dx / D;
        y = Dy / D;

        printf("\n=== Solution ===\n");
        printf("x = %.2f\n", x);
        printf("y = %2f\n", y);
    }

    return 0;
}
