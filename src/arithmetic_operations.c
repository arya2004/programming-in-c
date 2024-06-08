#include <stdio.h>

// Function to perform arithmetic operations based on user input
void performArithmetic() {
    float a, b;
    int op;

    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    printf("Enter the values of a & b: ");
    scanf("%f %f", &a, &b);
    printf("Enter your Choice: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Sum of %f and %f is : %f\n", a, b, a + b);
            break;
        case 2:
            printf("Difference of %f and %f is : %f\n", a, b, a - b);
            break;
        case 3:
            printf("Multiplication of %f and %f is : %f\n", a, b, a * b);
            break;
        case 4:
            printf("Division of Two Numbers is %f\n", a / b);
            break;
        default:
            printf("Enter Your Correct Choice.\n");
            break;
    }
}

int main() {
    performArithmetic(); // Example usage
    return 0;
}
