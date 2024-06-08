/**
 * Prints the multiplication table of a given number.
 * @param a - The number for which the table is generated.
 */
void table(int a) {
    for (int i = 1; i <= 10; i++) {
        printf("%i x %2i = %3i\n", a, i, a * i);
    }
}
