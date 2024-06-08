#include <stdio.h>

// Function to print a diamond pattern of given height
void printDiamond(int height) {
    // Print upper half of the diamond
    for (int row = 1; row <= height; row++) {
        for (int blank = 1; blank <= height - row; blank++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * row) - 1; star++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Print bottom half of the diamond
    for (int row = height - 1; row >= 1; row--) {
        for (int blank = height - row; blank >= 1; blank--) {
            printf(" ");
        }
        for (int star = (2 * row) - 1; star >= 1; star--) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a pattern with alphabets
void printAlphabetPattern(int height) {
    // Print upper half of the pattern
    for (int row = 1; row <= height; row++) {
        for (int left = 'A'; left <= ('A' + height - row); left++) {
            printf("%c", left);
        }
        for (int blank = 1; blank < (2 * row) - 1; blank++) {
            printf(" ");
        }
        for (int right = ('A' + height - row); right >= 'A'; right--) {
            printf("%c", right);
        }
        printf("\n");
    }
    
    // Print bottom half of the pattern
    for (int row = height - 1; row >= 1; row--) {
        for (int left = ('A' + height - row); left >= 'A'; left--) {
            printf("%c", left);
        }
        for (int blank = (2 * row) - 1; blank > 1; blank--) {
            printf(" ");
        }
        for (int right = 'A'; right <= ('A' + height - row); right++) {
            printf("%c", right);
        }
        printf("\n");
    }
}

// Function to count occurrences of digits in a string
void countDigits() {
    int counts[10] = {0}; // Initialize an array to store counts of digits
    char input[1000];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            int digit = input[i] - '0'; // Convert char to int
            counts[digit]++;
        }
    }
    
    // Print the counts of each digit
    for (int l = 0; l < 10; l++) {
        printf("%i ", counts[l]);
    }
    printf("\n");
}

// Function to print a pattern using numbers
void printNumberPattern(int n) {
    int length = (2 * n) - 1;
    int b = n;
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%i", n - j);
        }
        for (int k = length; k >= 0; k = k + 2) {
            printf("%i", b);
        }
        b = b - 1;
        for (int l = i; l >= 0; l = l - 1) {
            printf("%i", -(l - n));
        }
        printf("\n");
    }
}

int main() {
    int height = 5;
    
    printf("Diamond Pattern:\n");
    printDiamond(height);
    
    printf("\nAlphabet Pattern:\n");
    printAlphabetPattern(height);
    
    printf("\nDigit Counts:\n");
    countDigits();
    
    printf("\nNumber Pattern:\n");
    printNumberPattern(height);
    
    return 0;
}
