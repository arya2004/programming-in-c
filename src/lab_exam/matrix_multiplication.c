#include <stdio.h>

/**
 * Multiplies two matrices and prints the result.
 */
void matrix_mul(void) {
    int brow, bcol, arow, acol;
    float sum = 0;
    float a[10][10], b[10][10], c[10][10];

    // Input matrix dimensions
    printf("\nEnter the number of rows for the first matrix: ");
    scanf("%i", &arow);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%i", &acol);
    printf("Enter the number of rows for the second matrix: ");
    scanf("%i", &brow);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%i", &bcol);

    // Check if matrices can be multiplied
    if (acol != brow) {
        printf("Matrix multiplication not possible.");
    } else {
        // Input elements for matrix a
        printf("\nEnter elements for matrix a:\n");
        for (int c = 0; c < arow; c++) {
            for (int d = 0; d < acol; d++) {
                scanf("%f", &a[c][d]);
            }
        }

        // Input elements for matrix b
        printf("\nEnter elements for matrix b:\n");
        for (int cc = 0; cc < brow; cc++) {
            for (int dd = 0; dd < bcol; dd++) {
                scanf("%f", &b[cc][dd]);
            }
        }

        // Multiply matrices and print result
        printf("\nMatrix multiplication result:\n");
        for (int ccc = 0; ccc < arow; ccc++) {
            for (int ddd = 0; ddd < bcol; ddd++) {
                for (int k = 0; k < brow; k++) {
                    sum += a[ccc][k] * b[k][ddd];
                }
                c[ccc][ddd] = sum;
                sum = 0;
            }
        }

        // Print result matrix
        for (int ee = 0; ee < arow; ee++) {
            for (int ww = 0; ww < bcol; ww++) {
                printf("%.2f\t", c[ee][ww]); //prints 2 digit after decimal
            }
            printf("\n");
        }
    }
}
