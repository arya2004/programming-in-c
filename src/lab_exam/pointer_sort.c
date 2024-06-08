/**
 * Sorts an array using pointers.
 * @param a - Pointer to the array to sort.
 * @param n - Number of elements in the array.
 */
void ptr_sort(int *a, int n) {
    int tmp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
    printf("\nThe elements in the array after sorting:\n");
    for(int i = 0; i < n; i++) {
        printf(" element - %d : %d \n", i + 1, *(a + i));
    }         
    printf("\n");
}
