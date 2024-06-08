

#include "image.h" // Include the necessary header file for image operations

/*
 * Function: raster_circle
 * ------------------------
 * Rasterizes a circle on the given image using Bresenham's circle drawing algorithm.
 *
 * img: The image on which the circle will be drawn.
 * x0, y0: The coordinates of the center of the circle.
 * radius: The radius of the circle.
 * r, g, b: The color components for the circle.
 */
void raster_circle(image img, unsigned int x0, unsigned int y0, unsigned int radius,
                    color_component r, color_component g, color_component b)
{
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    // Plot the initial points at the cardinal directions
    plot(x0, y0 + radius);
    plot(x0, y0 - radius);
    plot(x0 + radius, y0);
    plot(x0 - radius, y0);

    // Bresenham's circle drawing algorithm
    while (x < y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x + 1;

        // Plot the points using symmetry
        plot(x0 + x, y0 + y);
        plot(x0 - x, y0 + y);
        plot(x0 + x, y0 - y);
        plot(x0 - x, y0 - y);
        plot(x0 + y, y0 + x);
        plot(x0 - y, y0 + x);
        plot(x0 + y, y0 - x);
        plot(x0 - y, y0 - x);
    }
}
