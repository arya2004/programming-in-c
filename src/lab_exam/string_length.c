#include <string.h>

/**
 * Calculates and returns the length of a string using strlen function.
 * @param s - The string.
 * @return The length of the string.
 */
int strle(char s[]) {
    return strlen(s);
}

/**
 * Calculates and returns the length of a string without using strlen function.
 * @param s - The string.
 * @return The length of the string.
 */
int mystrln(char *s) {
    int i = 0;
    for (; *(s) != '\0'; s++, i++);
    return i;
}
