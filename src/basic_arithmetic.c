#include <stdio.h>

// Function to perform basic arithmetic operations based on input operation code
void performArithmetic(float a, float b, int operation) {
    switch (operation) {
        case 1:
            printf("%f\n", a + b); // Addition
            break;
        case 2:
            printf("%f\n", a - b); // Subtraction
            break;
        case 3:
            printf("%f\n", a * b); // Multiplication
            break;
        case 4:
            printf("%f\n", a / b); // Division
            break;
        case 5:
            printf("%f, %f\n", a * a, b * b); // Square of numbers
            break;
        case 6:
            printf("%f, %f\n", sqrtf(a), sqrtf(b)); // Square root of numbers
            break;
    }
}

// Main function
int main() {
    performArithmetic(10.5, 5.0, 1); // Example usage
    return 0;
}
