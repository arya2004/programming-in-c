#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>








int Table(int _a, int _b) {
   for (int i = 1; i < 11; i++)
   {
        for (int j = _a; j < _a + _b; j++)
        {
            printf("%5i ", i * j);
        }
        printf("\n");
   }
   
   return 0;
    
} 


int main()
{   
    int a, b;
    //enter a, b,c separated by a space
    scanf("%i %i", &a, &b);
    
    Table(a, b);
   


    return 0;
}	

 