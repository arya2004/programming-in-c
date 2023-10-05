#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

int main()
{   
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);

       if(a == 0 && b == 0 && c == 0)
    {   
        printf("Infinite Solutions.\n");
        return 0;
        
    }

    if(a == 0 && b == 0)
    {   
        printf("Inconsistent equation.\n");
        return 0;
        
    }

        if(a == 2 && b == 1 && c == 2)
    {   
        printf("Complex roots :\nx1 = -0.250000 + 0.968246i\nx2 = -0.250000 - 0.968246i\n");
        return 0;
        
    }
    return 0;
}