/**
 * Swaps the values of two integers using pointers.
 * @param a - Pointer to the first integer.
 * @param b - Pointer to the second integer.
 */
void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
