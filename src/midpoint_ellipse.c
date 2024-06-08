#include <stdio.h>

/**
 * @brief Draws an ellipse using the midpoint ellipse algorithm.
 * 
 * @param rx Major radius of the ellipse.
 * @param ry Minor radius of the ellipse.
 * @param xc X-coordinate of the center of the ellipse.
 * @param yc Y-coordinate of the center of the ellipse.
 */
void midptellipse(int rx, int ry, int xc, int yc) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Debug output
    printf("Initial values: d1 = %f, dx = %f, dy = %f\n", d1, dx, dy);

    // For region 1
    while (dx < dy) {
        printf("Region 1 - Pixel Position: (%f, %f)\n", x + xc, y + yc);
        printf("Before update: dx = %f, dy = %f, d1 = %f\n", dx, dy, d1);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }

        printf("After update: dx = %f, dy = %f, d1 = %f\n", dx, dy, d1);
    }

    // Initial decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);

    // Debug output
    printf("\nInitial value of d2 = %f\n", d2);

    // For region 2
    while (y >= 0) {
        printf("Region 2 - Pixel Position: (%f, %f)\n", x + xc, y + yc);
        printf("Before update: dx = %f, dy = %f, d2 = %f\n", dx, dy, d2);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }

        printf("After update: dx = %f, dy = %f, d2 = %f\n", dx, dy, d2);
    }
}

/**
 * @brief Main function to demonstrate the midpoint ellipse algorithm.
 */
int main() {
    // Draw an ellipse with major radius 7 and minor radius 5 centered at (0, 0)
    midptellipse(7, 5, 0, 0);

    return 0;
}
