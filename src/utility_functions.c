#include <stdio.h>

/**
 * @brief Swaps values of two integers using pointers.
 */
void swapp(int *a, int *b) {
    *a = *b + *a;
}
