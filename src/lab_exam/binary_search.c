/**
 * Performs binary search recursively on an array.
 * @param x - The array to search in.
 * @param middle - The middle index of the current search range.
 * @param number - The number to search for.
 * @param lower - The lower index of the current search range.
 * @param highest - The highest index of the current search range.
 * @return The index of the number if found, otherwise -1.
 */
int binary_s_rec(int x[], int middle, int number, int lower, int highest) {
    if (x[middle] == number) {
        return middle;
    } else if (x[middle] > number) {
        return binary_s_rec(x, (middle - lower) / 2, number, lower, middle);
    } else if (x[middle] < number) {
        return binary_s_rec(x, (highest + middle) / 2, number, middle, highest);
    }
    return -1; // Number not found
}
