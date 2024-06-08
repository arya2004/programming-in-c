#include <stdio.h>

// Function to calculate the sum of digits using while loop
void sumOfDigitsWhileLoop(int dividend) {
    int summation = 0;
    int quotient, remainder;

    while (dividend != 0) {
        quotient = dividend / 10;
        remainder = dividend % 10;
        summation += remainder;
        dividend = quotient;
    }

    printf("Sum of digits using while loop: %i\n", summation);
}

// Function to calculate the sum of digits using do-while loop
void sumOfDigitsDoWhileLoop(int dividend) {
    int summation = 0;
    int quotient, remainder;

    do {
        quotient = dividend / 10;
        remainder = dividend % 10;
        summation += remainder;
        dividend = quotient;
    } while (quotient != 0);

    printf("Sum of digits using do-while loop: %i\n", summation);
}

// Function to count the number of digits using do-while loop
void countDigits(int dividend) {
    int count = 0;
    int quotient;

    do {
        quotient = dividend / 10;
        count++;
        dividend = quotient;
    } while (quotient != 0);

    printf("Number of digits: %i\n", count);
}

int main() {
    sumOfDigitsWhileLoop(12345); // Example usage
    sumOfDigitsDoWhileLoop(1066); // Example usage
    countDigits(12345); // Example usage
    return 0;
}
