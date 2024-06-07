#include <stdio.h>

/**
 * @brief Shifts array elements by left shifting binary bits.
 */
void two() {
    int a[50] = {1,2,3,4,5,6,7,8,9};
    int pos = 3;
    for(int i = 3; i < 10; ++i) {
        a[i] <<= 32;
    }
    for (int i = 0; i < 10; i++) {
        printf("%i\n", a[i]);
    }
    
    a[3] = 88;
    for (int i = 0; i < 10; i++) {
        printf("%i\n", a[i]);
    }
}

/**
 * @brief Inserts an element at a specified position in an array.
 */
void last() {
    int a[10] = {2,4,6,8,10,12,14,16,18};
    int size = 10;
    int pos = 7;
    int digit = 32;
    for (int i = size; i > pos; i--) {
        a[i] = a[i-1];
    }
    a[pos] = 32;
    for (int ii = 0; ii < size; ii++) {
        printf("%i\n", a[ii]);
    }
}
