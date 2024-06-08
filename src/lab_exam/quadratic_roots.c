#include <stdio.h>
#include <math.h>

/**
 * Calculates and prints the roots of a quadratic equation.
 * @param a - Coefficient of x^2.
 * @param b - Coefficient of x.
 * @param c - Constant term.
 */
void roots(double a, double b, double c) {
    // Calculate discriminant
    double discriminant = b * b - 4 * a * c;
    double root1, root2, imaginaryPart;

    // Determine type of roots and calculate accordingly
    if (discriminant > 0) {
        // Real and different roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\nThe roots are real and different.\n");
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    } else if (discriminant == 0) {
        // Real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("\nThe roots are real and same.\n");
        printf("root1 = root2 = %.2lf;", root1);
    } else {
        // Complex roots
        root1 = root2 = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("\nThe roots are complex and different.\n");
        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi", root1, imaginaryPart, root2, imaginaryPart);
    }
}
