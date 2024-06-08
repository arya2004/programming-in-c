/**
 * Performs arithmetic operations based on the operator.
 * @param a - First operand.
 * @param b - Second operand.
 * @param op - Operator ('a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for division).
 * @return 0 on success.
 */
int z(float a, float b, char op) {
    switch (op) {
        case 'a':
            printf("Sum of %f and %f is : %f", a, b, a + b);
            break;
        case 's':
            printf("Difference of %f and %f is : %f", a, b, a - b);
            break;
        case 'm':
            printf("Multiplication of %f and %f is : %f", a, b, a * b);
            break;
        case 'd':
            printf("Division of Two Numbers is %f : ", a / b);
            break;
        default:
            printf("Enter Your Correct Choice.");
            break;
    }
    return 0;
}
