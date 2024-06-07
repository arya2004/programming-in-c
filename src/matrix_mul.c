#include <stdio.h>

/**
 * @brief Performs matrix multiplication.
 */
void matrix_mul() {
    int brow, bcol, arow, acol;
    float sum = 0;
    float a[10][10], b[10][10], c[10][10];

    // Input matrix dimensions
    printf("\nEnter the number of rows for the first matrix\n");
    scanf("%i", &arow);
    printf("\nEnter the number of columns for the first matrix\n");
    scanf("%i", &acol);
    printf("\nEnter the number of rows for the second matrix\n");
    scanf("%i", &brow);
    printf("\nEnter the number of columns for the second matrix\n");
    scanf("%i", &bcol);

    // Check for valid matrix dimensions
    if (acol != brow) {
        printf("Error: Matrix multiplication is not possible with these dimensions.\n");
        return;
    }

    // Input elements for matrices
    printf("\nEnter elements for matrix A\n");
    for (int c = 0; c < arow; c++) {
        for (int d = 0; d < acol; d++) {
            scanf("%f", &a[c][d]);
        }
    }

    printf("\nEnter elements for matrix B\n");
    for (int cc = 0; cc < brow; cc++) {
        for (int dd = 0; dd < bcol; dd++) {
            scanf("%f", &b[cc][dd]);
        }
    }

    // Matrix multiplication
    for (int ccc = 0; ccc < arow; ccc++) {
        for (int ddd = 0; ddd < bcol; ddd++) {
            for (int k = 0; k < brow; k++) {
                sum += a[ccc][k] * b[k][ddd];
            }
            c[ccc][ddd] = sum;
            sum = 0;
        }
    }

    // Print the result matrix
    printf("\nResultant matrix:\n");
    for (int ee = 0; ee < arow; ee++) {
        for (int ww = 0; ww < bcol; ww++) {
            printf("%.2f\t", c[ee][ww]);
        }
        printf("\n");
    }
}

int main() {
    matrix_mul(); // Call the matrix multiplication function
    return 0;
}
