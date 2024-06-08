#include <stdio.h>

// Function to check if a year is a leap year or not
void checkLeapYear(int year) {
    (year % 4 == 0 ? (year % 400 == 0 ? printf("Leap Year\n") : printf("Not Leap Year\n")) : printf("Not Leap Year\n"));
}

// Main function
int main() {
    checkLeapYear(2024); // Example usage
    return 0;
}
