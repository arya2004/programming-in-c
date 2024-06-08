#include <stdio.h>

// Function to reverse an array
void reverseArray(int ary[], int array_size) {
    int middle_element;

    for (int i = 0; i <= (array_size / 2); i++) {
        middle_element = ary[i];
        ary[i] = ary[array_size - i];
        ary[array_size - i] = middle_element;
    }

    printf("Reversed Array:\n");
    for (int j = 0; j < array_size; j++) {
        printf("%i\n", ary[j]);
    }
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    reverseArray(array, size);
    return 0;
}
