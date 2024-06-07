#include <stdio.h>
#include <string.h>

/**
 * @brief Checks the existence of a substring in a main string.
 */
void exist() {
    char x[300], y[100];
    printf("\nEnter the main string\n");
    gets(x);
    printf("\nEnter the substring\n");
    gets(y);

    int search_order, req, output = -1, occurence = 0, flag = 0, xx = strlen(x), yy = strlen(y);

    printf("\nEnter the search order (0 for left to right, 1 for right to left)\n");
    scanf("%i", &search_order);
    printf("\nEnter the value of N for the Nth occurrence\n");
    scanf("%i", &req);

    // Search for the substring
    if (search_order == 0) {
        for (int i = 0; i < xx; i++) {
            if (x[i] == y[0]) {
                for (int j = 1; j < yy; j++) {
                    if (x[i + j] != y[j]) {
                        flag = 0;
                        continue;
                    }
                    flag = 1;
                }
            }
            if (flag == 1) {
                occurence++;
                flag = 0;
            }
            if (req == occurence) {
                output = i;
                break;
            }
        }
    } else if (search_order == 1) {
        for (int i = xx; i >= 0; i--) {
            if (x[i] == y[0]) {
                for (int j = 1; j < yy; j++) {
                    if (x[i + j] != y[j]) {
                        flag = 0;
                        continue;
                    }
                    flag = 1;
                }
            }
            if (flag == 1) {
                occurence++;
                flag = 0;
            }
            if (req == occurence) {
                output = i;
                break;
            }
        }
    }

    // Output the result
    if (output != -1) {
        printf("\nThe substring \"%s\" exists in the main string at index %i.\n", y, output);
    } else {
        printf("\nThe substring \"%s\" does not exist in the main string.\n", y);
    }
}

int main() {
    exist(); // Call the substring existence function
    return 0;
}
