#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reverses an array of integers.
 */
int Main(void) {
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    int *p;
    p = arr + num;
    for(i = 0; i < num/2; i++, p = p - 1, arr = arr + 1) {
        int temp = *arr;
        *arr = *p;
        *p = temp;
    }
    // Print the reversed array here if needed
    return 0;
}
