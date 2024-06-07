#include <stdio.h>

/**
 * @brief Concatenates two strings.
 * 
 * @param s The destination string.
 * @param t The source string.
 */
void fun(char *s, char *t) {
    while(*++s); // Takes pointer s to the end of the first string
    while(*s++ = *t++);
}

/**
 * @brief Copies characters from t to s.
 * 
 * @param n Number of characters to copy.
 * @param s The destination string.
 * @param t The source string.
 */
void pp(int n, char *s, char *t) {
    if (n > 0) {
        *s = *t;
        pp(n - 1, s = s + 1, t = t + 1); 
    }
}
