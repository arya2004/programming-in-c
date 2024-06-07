#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * @brief Converts a string to an integer, handling negative numbers and overflow.
 * 
 * @param s The input string.
 * @return The converted integer value.
 */
long int myAtoi(char *s) {
    long int r = 0;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    
    for(int i = 0; s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '-' || s[i] == '+'); i++) {
        if(s[i] == '-') {
            r = -r;
        }
        if(s[i] <= pow(-2, 31)) {
            return -2147483648;
        }
        else if(s[i] >= pow(2, 31) - 1) {
            return 2147483647;
        }
        else if(s[i] >= '0' && s[i] <= '9') {
            int j = s[i] - 48;
            r = r * 10;
            r = r + a[j];
        }
    }
    return r;
}
