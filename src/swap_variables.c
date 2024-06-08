#include <stdio.h>

// Function to swap two variables using comma operator
void swapVariables(int a, int b) {
    a, b = b, a; // Using comma operator for swapping
    printf("Swapped values: a = %i, b = %i\n", a, b);
}

// Main function
int main() {
    swapVariables(5, 10); // Example usage
    return 0;
}
