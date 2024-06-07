#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to swap two integers using XOR
void integerSwap(void) {
    int a = 77;
    int b = 55;

    // Print initial values
    printf("Initial values: a = %i, b = %i\n", a, b);

    // Swap using XOR operations
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    // Print swapped values
    printf("Swapped values: a = %i, b = %i\n", a, b);
}

// Function to compute 2's complement of an integer
void twoComplement(void) {
    int a = 77;

    // Print original value
    printf("Original value: %i\n", a);

    // Compute 2's complement
    a = ~a;
    a = a + 1;

    // Print 2's complement
    printf("2's complement: %i\n", a);
}

// Struct representing a date with integers
struct Date1 {
    int day, month, year;
};

// Struct representing a date with bit fields
struct Date2 {
    unsigned int day : 5;
    unsigned int month : 4;
    int year : 12;
};

// Struct demonstrating memory alignment
struct ExampleStruct {
    int x;
    char y;
    char y1;
    char y2;
    char y3;
    char y4;
    double z;
};

// Union demonstrating memory sharing
union ExampleUnion {
    int x;
    char y;
    double z;
};

// Function to convert a decimal number to binary recursively
void decimalToBinary(int n) {
    if (n > 0) {
        decimalToBinary(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    // Example usage of functions and data structures
    integerSwap();
    twoComplement();

    struct Date1 dob;
    dob.day = 8;
    dob.month = 1;
    dob.year = 1980;

    struct Date2 dob2;
    dob2.day = 8;
    dob2.month = 1;
    dob2.year = 1980;

    struct ExampleStruct example;
    union ExampleUnion exampleUnion;

    // Print sizes of data types
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of struct Date1: %lu bytes\n", sizeof(struct Date1));
    printf("Size of struct Date2: %lu bytes\n", sizeof(struct Date2));
    printf("Size of struct ExampleStruct: %lu bytes\n", sizeof(struct ExampleStruct));
    printf("Size of union ExampleUnion: %lu bytes\n", sizeof(union ExampleUnion));

    // Convert decimal to binary
    int decimalNumber = 14;
    printf("Binary representation of %d is: ", decimalNumber);
    decimalToBinary(decimalNumber);
    printf("\n");

    return 0;
}
