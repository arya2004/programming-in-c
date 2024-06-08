#include <stdio.h>

// Function to calculate the sum of corresponding elements of two arrays
void calculateTwoArraySum(int arr1[5], int arr2[5]) {
    int sumArray[5];
    for (int i = 0; i < 5; i++) {
        sumArray[i] = arr1[i] + arr2[i];
        printf("%i\n", sumArray[i]);
    }
}

// Main function
int main() {
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {5, 4, 3, 2, 1};
    calculateTwoArraySum(array1, array2);
    return 0;
}
