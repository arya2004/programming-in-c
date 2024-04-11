#include<stdio.h>
#include<conio.h>
#include<stdlib>

int z()
{
    float a,b;
    int op;
    printf(" 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    printf("Enter the values of a & b: ");
    scanf("%d %d",&a,&b);
    printf("Enter your Choice : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1	:
        printf("Sum of %f and %f is : %d",a,b,a+b);
        break;
    case 2	:
        printf("Difference of %f and %f is : %d",a,b,a-b);
        break;
    case 3	:
        printf("Multiplication of %f and %f is : %d",a,b,a*b);
        break;
    case 4	:
        printf("Division of Two Numbers is %f : ",a/b);
        break;
    default	:
        printf(" Enter Your Correct Choice.");
        break;
    }
    return 0;
}

void a(int i, int z){while (i <= z){int k = 0;printf("%i\n",i);i = i + 1;}}

void b(int i, int z){while (i <= z){if (i%2 == 1){printf("Odd%i\n", i);i = i + 1;}else if (i%2 == 0){printf("Even%i\n", i);i = i + 1;}}}

 void sumofdig(int dividend){
    int summation = 0;
    int quotient;       // using while loop
    int remainder;
    while (dividend != 0)
    {
      quotient = dividend / 10;
      remainder = dividend % 10;
      summation = summation + remainder;
      dividend = quotient;
}
    printf("%i", summation); 
 }   
    
 void sumofdigits(int dividend){
    int summation = 0;
    int quotient;  // using do-while loop
    int remainder;
    do
    {
      quotient = dividend / 10;
      remainder = dividend % 10;
      summation = summation + remainder;
      dividend = quotient;
}
     while (quotient != 0);
    

    printf("%i", summation); 
 }   
    
 void noofdig(int dividend){
    int summation = 0;
    int quotient;  // using do-while loop
    int remainder;
    do
    {
      quotient = dividend / 10;
      remainder = dividend % 10;
      summation = summation + 1;
      dividend = quotient;
}
     while (quotient != 0);
    

    printf("%i", summation); 
 } 


void reverse(int ary[], int array_size){
    int middle_element;
    for (int i = 0; i <= ((array_size/2)) ; i++){
        middle_element = ary[i];
        ary[i] = ary[array_size - i];
        ary[array_size - i] = middle_element;
    }
    for (int j = 0; j < array_size; j++)
    {
        printf("%i\n",ary[j]);
    }
}

int main(){
    //sumofdig(1000245);
    //sumofdigits(1066);
    //noofdig(123343);
    int ary[10] = {1,2,3,4,5,6,7,8,9,10};
    int s = 10;
    reverse(ary,s);
    
    
    return 0;
}