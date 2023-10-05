#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

/*
Problem Statement: 

You are given a quadratic equation in the form:

ax^2 + bx + c = 0

Your task is to implement a C program that finds the roots of the given  equation and prints the results according to the following rules:

First Line:
If the equation has infinite solutions (i.e., a = 0, b = 0, c = 0), print "infinite".
If the equation has no solutions (i.e a = 0, b = 0), print "inconsistent".
If equation has real roots, print the 'real', else print the 'imaginary'.
If input is invalid (one of input is char) then print 'invalid input'

Second Line (If applicable):
If 'a' is equal to 0 (making it a linear equation), print the real root of the linear equation.
If the equation has two distinct real roots, print both roots as two real numbers.
If the equation has one real root, print it as a single real number.
If the equation has complex roots, print them as a pair of complex numbers in the format "real_part + imaginary_parti", where "i" represents the imaginary unit.




Input:
The coefficients a, b, and c of the quadratic equation separated by a space (-10^8 <= |a|, |b|, |c| <= 3.4028234664e+38).

Output:

Print the result according to the conditions described above.
Round-off to 2 decimal places

Examples:

Input:
1.0 2.0 1.0
Output:
real
-1.00


Input:
0 -3.4028234664e+38 3.4028234664e+38
Output:
real
1.00 

Input:
0000 0.00 0.0
Output:
infinite

Input:
0 b b
Output:
invalid input

Input:
2 1 2
Output:
imaginary
-0.25+0.97i
-0.25-0.97i

Note:

>Print the results with two decimal places for real numbers.
>Handle the cases where 'a' is equal to 0 and print the real root for linear equations.
>sqrt() function is available in ‘math.h’ library, you may have to use it.
>You may use ‘multiple ifs ladder’ or ‘if else if ladder’
>In main you are allowed to use ‘return’ statement at multiple places and program immediately 
>Stops when program flow arrives at any of the return statements.
>Round-off after doing all other arithmetic calculation
>Check for overflow when squaring. Do you think 'int' can handle this?

Hint to check whether input is invalid:
The scanf() function returns the number of fields that were successfully CONVERTED AND ASSIGNED. The return value does not include fields that were read but NOT ASSIGNED.

*/





int Check_validity(float _a, float _b, float _c)
{
     if(_a == 0 && _b == 0 && _c == 0)
    {   
        printf("Infinite Solutions.\n");
        return 0;
        
    }

    if(_a == 0 && _b == 0)
    {   
        printf("Inconsistent equation.\n");
        return 0;
        
    }
    return 1;
}

int isLinear(float _a, float _b, float _c)
{
    return _a == 0;
}


int Quadratic(float _a, float _b, float _c) {
   
   
    if(!(Check_validity(_a,_b,_c)))
    {
        return 0;
    }
    else if(isLinear(_a,_b,_c))
    {
        float linear_root = -(_c/_b);
        printf("Linear equation with single solution x = %f", linear_root);
        return 0;
    }    

    float discriminant = (_b * _b )- (4 * _a * _c);

    // real and diff root
    if (discriminant > 0) 
    {
        float root1 = (-_b + sqrt(discriminant)) / (2 * _a);
        float root2 = (-_b - sqrt(discriminant)) / (2 * _a);
        printf("Real and distinct roots :\n");
        printf("x1 = %f\n", root1);
        printf("x2 = %f\n",root2);
        return 0;
    }

    // real and same
    else if (discriminant == 0) 
    {
        float r1 = -_b / (2 * _a);
        printf("Real and repeated roots :\n");
        printf("x1 = %f\n", r1);
        printf("x2 = %f\n", r1);
        return 0;
    }

        //imaginary
    else 
    {
       float real = -_b / (2 * _a);
       float imag = sqrt(-discriminant) / (2 * _a);
        printf("Complex roots :\n");
        printf("x1 = %f + %fi\n",real, imag);
        printf("x2 = %f - %fi\n", real, imag);
        return 0;
    }
} 


int main()
{   
   if(!printf("HEllo ")){
    printf("HEllo");
   }
   else{
    printf("world");
   }


    return 0;
}	

 