#include <stdio.h>

// Function to determine if a number is positive, negative, or zero using conditional expressions
void determineNumberType(int num) {
    (num >= 0 ? (num == 0 ? printf("Zero\n") : printf("Positive\n")) : printf("Negative\n"));
}

// Main function
int main() {
    determineNumberType(-7); // Example usage
    return 0;
}
