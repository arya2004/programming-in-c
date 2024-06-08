#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to demonstrate different ways of initializing integers
void demonstrateIntegerInitialization(void) {
    int octalNumber = 05312; // base 8 %o
    int hexadecimalNumber = 0xA; // base 16 %x
    float exponentNotation = 3.4e4; // exponent %g
    int binaryNumber = 0b1011; // binary
    printf("%i\n", binaryNumber);
}

// Main function
int main() {
    demonstrateIntegerInitialization();
    return 0;
}
