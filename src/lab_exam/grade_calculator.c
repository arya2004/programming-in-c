/**
 * Calculates and prints the grade based on average marks.
 * @param a - Mark 1.
 * @param b - Mark 2.
 * @param c - Mark 3.
 * @param d - Mark 4.
 * @param e - Mark 5.
 * @return 0 on success.
 */
int grade(float a, float b, float c, float d, float e) {
    // Calculate average
    float avg = (a + b + c + d + e) / 5;

    // Determine grade based on average
    if (avg > 90) {
        printf("Grade is A");
    } else if (avg > 70 && avg <= 90) {
        printf("Grade is B");
    } else if (avg > 50 && avg <= 70) {
        printf("Grade is C");
    } else if (avg > 35 && avg <= 50) {
        printf("Grade is D");
    } else {
        printf("Grade is F");
    }

    return 0;
}
