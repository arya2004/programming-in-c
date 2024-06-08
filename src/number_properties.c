#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}

// Main function
int main() {
    checkEvenOdd(7); // Example usage
    return 0;
}
