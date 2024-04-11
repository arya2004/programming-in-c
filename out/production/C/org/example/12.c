#include <stdio.h>
 
void midptellipse(int rx, int ry, int xc, int yc)
{
 
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
 
    // Initial decision parameter of region 1
    d1 = (ry * ry)
         - (rx * rx * ry)
         + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
  printf(" d1 inint(%f)\n",d1);
  printf(" dx inint(%f)\n",dx);
  printf(" dy inint(%f)\n",dy);
    // For region 1
    while (dx < dy) {
         printf("Dx, dy, d1 before(%f, %f, %f)\n", dx,dy, d1);
        printf("PIxel Position: (%f, %f)\n", x + xc, y + yc);
        // printf("(%f, %f)\n", -x + xc, y + yc);
        // printf("(%f, %f)\n", x + xc, -y + yc);
        // printf("(%f, %f)\n", -x + xc, -y + yc);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
        printf("Dx, dy, d1 after(%f, %f, %f)\n", dx,dy, d1);
    }
    printf(" \n\n\n");
 
//r2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);
 
     printf(" d2 inint(%f)\n",d2);
    while (y >= 0) {
 
      printf("Dx, dy, d2 before(%f, %f, %f)\n", dx,dy, d2);
        printf("PIxel Position: (%f, %f)\n", x + xc, y + yc);
        // printf("(%f, %f)\n", -x + xc, y + yc);
        // printf("(%f, %f)\n", x + xc, -y + yc);
        // printf("(%f, %f)\n", -x + xc, -y + yc);
 
      
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
         printf("Dx, dy, d2 after(%f, %f, %f)\n", dx,dy, d2);
    }
}
 

int main()
{
    // To draw a ellipse of major and
    // minor radius 15, 10 
    midptellipse(7, 5, 0, 0);
 
    return 0;
}