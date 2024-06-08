/**
 * Searches for a given element in an array and returns its index.
 * @param a - The array.
 * @param f - The element to search for.
 * @return The index of the element, -1 if not found.
 */
int ls(int a[], int f) {
    int loc = -1;
    for (int i = 0; a[i]; i++) {
        if (a[i] == f) {
            loc = i;
            break;
        }
    }
    return loc;
}

/**
 * Separates odd and even numbers from an array and prints them.
 * @param a - The array.
 */
void aeo(int a[]) {
    int o[100], e[100];
    int k = 0, l = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 == 0) {
            o[k++] = a[i];
        }
        if (a[i] % 2 == 1) {
            e[l++] = a[i];
        }
    }
    printf("\nodd\n");
    for (int ll = 0; ll < l; ll++) {
        printf("%i\n", e[ll]);
    }
    printf("\neven\n");
    for (int lll = 0; lll < k; lll++) {
        printf("%i\n", o[lll]);
    }
}
