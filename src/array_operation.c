#include <stdio.h>

// Function to print elements of an array
void printArray(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%i\n", arr[i]);
    }
}

// Function to print even and odd elements of an array
void printEvenOddElements(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] % 2 == 0) {
            printf("Even: %i\n", arr[i]);
        } else {
            printf("Odd: %i\n", arr[i]);
        }
    }
}

// Function to calculate the sum of elements in an array
void calculateArraySum(int arr[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("Sum: %i\n", sum);
}

// Main function
int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    printArray(numbers);
    printEvenOddElements(numbers);
    calculateArraySum(numbers);
    return 0;
}
