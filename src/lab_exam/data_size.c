/**
 * Calculates and prints the sizes of different data types.
 * @param a - An integer.
 * @param b - A double.
 * @param c - A character.
 * @param d - A float.
 */
void size_of(int a, double b, char c, float d) {
    // Print the sizes of various data types
    printf("Size of int is: %lu\n", sizeof(a));
    printf("Size of double is: %lu\n", sizeof(b));
    printf("Size of int + double is: %lu\n", sizeof(a + b));
    printf("Size of char is: %lu\n", sizeof(c));
    printf("Size of float is: %lu\n", sizeof(d));
}
