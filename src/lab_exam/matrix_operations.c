/**
 * Displays the elements of a 3x3 matrix.
 * @param matrix - The matrix to display.
 */
void display(int matrix[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            printf("%d\t",matrix[i][j]);
        printf("\n"); 
    }
}

/**
 * Adds two 3x3 matrices and prints the result.
 * @param m - The first matrix.
 * @param n - The second matrix.
 * @param sum - The matrix to store the sum.
 */
void add(int m[3][3], int n[3][3], int sum[3][3]) {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            sum[i][j] = m[i][j] + n[i][j];
    
    display(sum);
}

/**
 * Subtracts one 3x3 matrix from another and prints the result.
 * @param m - The matrix from which to subtract.
 * @param n - The matrix to subtract.
 * @param result - The matrix to store the result.
 */
void subtract(int m[3][3], int n[3][3], int result[3][3]) {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            result[i][j] = m[i][j] - n[i][j];

    display(result);
}

/**
 * Multiplies two 3x3 matrices and prints the result.
 * @param m - The first matrix.
 * @param n - The second matrix.
 * @param mul - The matrix to store the product.
 */
void multiply(int m[3][3], int n[3][3], int mul[3][3]) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            mul[i][j] = 0; 
            for (int k = 0; k < 3; k++)
                mul[i][j] += m[i][k] * n[k][j];
        }
    }
    
    display(mul);
}

/**
 * Transposes a 3x3 matrix and prints the result.
 * @param matrix - The matrix to transpose.
 * @param trans - The matrix to store the transposed matrix.
 */
void transpose(int matrix[3][3], int trans[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[j][i] = matrix[i][j];
        }
    }

    display(trans);
}
