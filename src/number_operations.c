#include <stdio.h>

// Function to print numbers in a range
void printNumbersInRange(int start, int end) {
    while (start <= end) {
        printf("%i\n", start);
        start++;
    }
}

// Function to print even and odd numbers in a range
void printEvenOddNumbersInRange(int start, int end) {
    while (start <= end) {
        if (start % 2 == 1) {
            printf("Odd %i\n", start);
        } else if (start % 2 == 0) {
            printf("Even %i\n", start);
        }
        start++;
    }
}

// Main function
int main() {
    printNumbersInRange(1, 10); // Example usage
    printEvenOddNumbersInRange(1, 10); // Example usage
    return 0;
}
