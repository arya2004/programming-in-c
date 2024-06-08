#include <stdio.h>

// Function to print the size of different data types
void printDataTypesSize(int a, double b, char c, float d) {
    printf("Size of int: %zu\n", sizeof(a));
    printf("Size of double: %zu\n", sizeof(b));
    printf("Size of char: %zu\n", sizeof(c));
    printf("Size of float: %zu\n", sizeof(d));
    printf("Size of int + double: %zu\n", sizeof(a + b));
}

// Main function
int main() {
    printDataTypesSize(10, 5.5, 'A', 3.14); // Example usage
    return 0;
}
