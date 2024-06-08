#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Global variable
int x = 2;

/**
 * Function to calculate the summation of numbers from 'a' to 99 using recursion.
 * @param a The starting number.
 * @return The summation of numbers from 'a' to 99.
 */
unsigned int Summation_using_recursion(unsigned int a) {
    if (a == 100) {
        return 1;
    } else {
        return a + Summation_using_recursion(a + 1);
    }
}

/**
 * Function that causes stack overflow error due to infinite recursion.
 * @param a The starting number.
 * @return Never returns, causes a stack overflow.
 */
unsigned int Summation_using_recursion_systemerror(unsigned int a) {
    return a + Summation_using_recursion_systemerror(a + 1);
}

/**
 * Function to calculate the absolute value of a float.
 * @param x The float number.
 * @return The absolute value of 'x'.
 */
float absolute_value(float x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

/**
 * Function to calculate the square root of a number using the Newton-Raphson method.
 * @param x The number to calculate the square root of.
 * @return The square root of 'x'.
 */
float square_root(float x) {
    float epsilon = 0.00001;
    float guess = 1.0;
    while (absolute_value(guess * guess - x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
    }
    return guess;
}

/**
 * Function to convert a string to lowercase.
 */
void smol(void) {
    char x[] = "WErTyuIopASdfGHJKlzXcvbnm123456789=[;.";
    for (int i = 0; x[i]; i++) {
        if (x[i] >= 'A' && x[i] <= 'Z') {
            x[i] = x[i] + ('a' - 'A');
        }
    }
    for (int j = 0; x[j]; j++) {
        printf("%c", x[j]);
    }
    printf("\n");
}

/**
 * Function to convert a string to uppercase.
 */
void bigg(void) {
    char x[] = "WErTyuIopASdfGHJKlzXcvbnm123456789=[;.";
    for (int i = 0; x[i]; i++) {
        if (x[i] >= 'a' && x[i] <= 'z') {
            x[i] = x[i] - ('a' - 'A');
        }
    }
    for (int j = 0; x[j]; j++) {
        printf("%c", x[j]);
    }
    printf("\n");
}

/**
 * Function to check if a substring exists within a string.
 */
void exist(void) {
    char x[] = "Console.WriteLine(Hello World! ); ";
    char y[] = "d! );";
    int flag = 0;
    int xx = strlen(x);
    int yy = strlen(y);
    for (int i = 0; i < xx; i++) {
        if (x[i] == y[0]) {
            flag = 1;
            for (int j = 1; j < yy; j++) {
                if (x[i + j] != y[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) break;
        }
    }
    if (flag == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

/**
 * Function to check if a string exists within an array of strings.
 */
void existarry(void) {
    char x[8][1000] = {"Hist", "Geo", "Math", "Sci", "Eng", "Mar", "Hin", "Ger"};
    char y[] = "Ger";
    int index = -1;
    int flag = 0;
    int xx = 8;
    int yy = strlen(y);
    for (int i = 0; i < xx; i++) {
        if (x[i][0] == y[0]) {
            flag = 1;
            for (int j = 1; j < yy; j++) {
                if (x[i][j] != y[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                index = i;
                break;
            }
        }
    }
    if (flag == 1) {
        printf("Yes\n");
        printf("%i\n", index);
    } else {
        printf("No\n");
        printf("%i\n", index);
    }
}

/**
 * Function to sort an array of integers using bubble sort.
 */
void sorter(void) {
    int x[10] = {4, 6, 2, 1, 10, 8, 9, 3, 7, 5};
    int z = 10;
    int temp;
    for (int i = 0; i < (z - 1); i++) {
        for (int j = i + 1; j < 10; j++) {
            if (x[i] > x[j]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
            for (int k = 0; k < 10; k++) {
                printf("%i ", x[k]);
            }
            printf("\n");
        }
    }
}

/**
 * Function to calculate the sum of three float numbers.
 * @param a The first float number.
 * @param b The second float number.
 * @param c The third float number.
 * @return The sum of 'a', 'b', and 'c'.
 */
float sum3(float a, float b, float c) {
    return a + b + c;
}

/**
 * Function to demonstrate printing of a variable twice.
 */
void aaa(void) {
    int x = 0;
    printf("%i", x);
    printf("%i", x);
}

/**
 * Function to find the nth occurrence of a substring in a string.
 */
void vv(void) {
    char main_string[100], substring[100];
    int direction, occurrence, count = 0, index = 0;
    printf("Enter main string: ");
    gets(main_string);
    printf("Enter substring: ");
    gets(substring);
    printf("Enter search direction (0: left to right, 1: right to left): ");
    scanf("%d", &direction);
    printf("Enter occurrence number: ");
    scanf("%d", &occurrence);

    if (direction == 0) {
        while (count != occurrence) {
            char *substring_index = strstr(main_string + index, substring);
            if (substring_index == NULL) {
                index = -1;
                break;
            }
            index = substring_index - main_string;
            count++;
            index++;
        }
    } else {
        int main_string_length = strlen(main_string);
        int substring_length = strlen(substring);
        while (count != occurrence) {
            char reversed_main_string[main_string_length + 1];
            char reversed_substring[substring_length + 1];
            int i, j;
            for (i = 0, j = main_string_length - 1; i < main_string_length; i++, j--) {
                reversed_main_string[i] = main_string[j];
            }
            reversed_main_string[i] = '\0';
            for (i = 0, j = substring_length - 1; i < substring_length; i++, j--) {
                reversed_substring[i] = substring[j];
            }
            reversed_substring[i] = '\0';
            char *substring_index = strstr(reversed_main_string + index, reversed_substring);
            if (substring_index == NULL) {
                index = -1;
                break;
            }
            index = substring_index - reversed_main_string;
            count++;
            index++;
        }
        index = main_string_length - index - substring_length;
    }

    if (index != -1) {
        printf("The index of the %d occurrence of the substring is: %d\n", occurrence, index);
    } else {
        printf("-1\n");
    }
}

/**
 * Main function to demonstrate the use of various utility functions.
 * @return Exit status of the program.
 */
int main() {

    unsigned int k = Summation_using_recursion_systemerror(4);
    printf("\n%i", k);

    sorter();
    existarry();
    aaa();
    vv();

    return 0;
}
