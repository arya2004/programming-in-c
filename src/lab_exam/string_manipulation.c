#include <string.h>

/**
 * Concatenates two strings and modifies the first string.
 * @param a - The first string.
 * @param b - The second string to concatenate.
 */
void strconc(char a[], char b[]) {
    strcat(a, b);
}

/**
 * Copies two strings into a third string.
 * @param a - The first string.
 * @param b - The second string.
 * @param c - The third string to store the result.
 */
void mystrcpy(char *a, char *b, char *c) {
    strcpy(c, a);
    strcat(c, " ");
    strcat(c, b);
}

/**
 * Copies one string into another using pointer manipulation.
 * @param a - The source string.
 * @param b - The destination string.
 */
void mystrcpy1(char *a, char *b) {
    while (*a++ = *b++);
}
