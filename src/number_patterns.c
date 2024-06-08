#include <stdio.h>

// Function to print a pattern of numbers
void printNumberPattern(int num) {
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function
int main() {
    printNumberPattern(5); // Example usage
    return 0;
}
