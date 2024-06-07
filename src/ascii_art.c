#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


int main() {
    // Initialize variables
    float angleA = 0, angleB = 0;
    float i, j;
    int k;
    float zBuffer[1760];
    char output[1760];

    // Clear the screen
    printf("\x1b[2J");

    // Infinite loop for animation
    for (;;) {
        // Reset the output buffer and depth buffer
        memset(output, 32, 1760);
        memset(zBuffer, 0, 7040);

        // Loop for generating ASCII art
        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                // Calculate trigonometric values
                float c = sin(i);
                float d = cos(j);
                float e = sin(angleA);
                float f = sin(j);
                float g = cos(angleA);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(angleB);
                float n = sin(angleB);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int index = x + 80 * y;
                int charIndex = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                // Check bounds and update ASCII art if necessary
                if (22 > y && y > 0 && x > 0 && 80 > x && D > zBuffer[index]) {
                    zBuffer[index] = D;
                    output[index] = ".,-~:;=!*#$@"[charIndex > 0 ? charIndex : 0];
                }
            }
        }

        // Print the ASCII art to the screen
        printf("\x1b[H");
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? output[k] : 10);
            angleA += 0.00004;
            angleB += 0.00002;
        }


    }

    return 0;
}
