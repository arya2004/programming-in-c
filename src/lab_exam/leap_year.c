/**
 * Checks if a given year is a leap year or not.
 * @param year - The year to check.
 */
void leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Leap");
    } else {
        printf("Not Leap");
    }
}
