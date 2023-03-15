#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

double Fact(double i) { //not unsigned long int, cause double stores more.useless after 15
    if(i <= 1) {
        return 1;
    }
    else{
        return i * Fact(i - 1);
    }
}


unsigned int Summation_using_recursion(unsigned int b){
     if(b == 1) {
        return 1;
    }
    else{
        return b + Summation_using_recursion(b - 1);
    }
}

double power(double a, unsigned int n ) {
    if(n == 0) {
        return 1;
    }
    else{
        return a * power(a , n-1);
    }
}

unsigned long int fib(unsigned int i) {
    int p = 0;
    if(i <= 1) {
        return 1;
    }
    else{
        return fib(i-1)+ fib(i-2);
     }
}

void prime(int a){
    for ( int dividend = 2; dividend <= a ; dividend++){
         for ( int divisor = 2; divisor < a ; divisor++){
            if (dividend % divisor == 0)
            {
                continue;
            }
            printf("%i\n", dividend);
            
         }
        
        
        
    }
    
}

void diamond(int height){
    //above
    for ( int row = 1; row <= height ; row++){
        for (int  blank = 1; blank <= height - row; blank++)
        {
            printf(" ");
        }
        
        for (int star = 1 ; star <= (2*row)- 1; star++)
        {
            printf("*");
        }
        printf("\n");
        }
    //bottom
    for ( int row = height; row >= 1 ; row--){
        for (int  blank = height - row; blank >= 1; blank--)
        {
            printf(" ");
        }
        
        for (int star = (2*row)- 1 ; star >= 1 ; star--)
        {
            printf("*");
        }
        printf("\n");
        }
    
}

void abc(int height){
    //left
     for ( int row = 1; row <= height ; row++){
        for (int  left = 65; left <= (height - row) + 65; left++)
        {
            printf("%c", left  );
        }
     // blanks   
        for (int blank = 1 ; blank < (2*row)- 1; blank++)
        {
            printf(" ");
        }
    // right    
        for (int  right = (height - row) + 65; right >= 65; right--)
        {
            printf("%c", right  );
        }
        printf("\n");
    
    }
}

void ary_ex(void){
    char name1[20] = "MILInd";
    for (int j = 0; j < 20; j++)
    {
        printf("%c",name1[j]);
    }
    
}

void ary_ex2(char c[], char d[] ){
    printf("HEllo %s \n", c);
    printf("HEllo %s", d);
}

void ary_avg(int c[]){
    float a = 0;
    for ( int i = 0; i < 7; i++)
    {
        a =  a + (float) c[i];
    }
    printf("AVg = %f", a/7);
}

void ary_sum(int c[]){
    float a = 0;
    for ( int i = 0; i < 7; i++)
    {
        a =  a + (float) c[i];
    }
    printf("Sum = %f\n", a);
}

void ary_mul(int c[]){
    float a = 1;
    for ( int i = 0; i < 7; i++)
    {
        a =  a * (float) c[i];
    }
    printf("multiplication = %f\n", a);
}

void ary_max(int c[]){
    float a = 0;
    for ( int i = 0; i < 7; i++)
    {
        if (c[i] > a)
        {
            a = c[i];
        }
        
    }
    printf("max = %i\n", a);
}

void ary_min(int c[]){
    float a = c[0];
    for ( int i = 0; i < 7; i++)
    {
        if (c[i]  < a)
        {
            a = c[i];
        }
        
    }
    printf("min = %i\n", a);
}

void ary_even(int c[]){
    for ( int i = 0; i < 7; i++)
    {
        if (c[i] % 2 == 0)
        {
            printf("even no = %i\n", c[i]);
        }
        
    }
    
}

void ary_odd(int c[]){
    for ( int i = 0; i < 7; i++)
    {
        if (c[i] % 2 == 1)
        {
            printf("odd no = %i\n", c[i]);
        }
        
    }
    
}

void aaary(void){
      int p[7] = {50,60,70,80,91,100,100};
    int a = 0;
    int b;
    printf(" 2.Avg\n 3.Sum\n 4.Mul\n 5.Max\n 6.Min\n 7.Even \n 8.Odd\n 1.Exit\n");
    while (a == 0){

    printf("Enter your Choice : ");
    scanf("%i",&b);
    switch(b)
    {
    case 1	:
        a = 1;
        continue;
    case 2	:
        ary_avg(p);
        continue;
    case 3	:
        ary_sum(p);
        continue;
    case 4	:
        ary_mul(p);
        continue;
    case 5	:
        ary_max(p);
        continue;
    case 6	:
        ary_min(p);
        continue;
    case 7	:
        ary_even(p);
        continue;
    case 8	:
        ary_odd(p);
        continue;
    default	:
        printf(" Enter Your Correct Choice.");
        continue;
    }
}
}

double e_x(float x){
    double result = 0;
    for (int j = 0; (power(x,j)/Fact(j)) > 0.000001; j++){
        result = result + (power(x,j)/Fact(j));
    }
    
    

    return result;
}

void display_dig(int n){
    if (n > 0)
    {
        display_dig(n/10);
        printf("%i ", n % 10);
    }
    
}

void kkkk(void){
    float a = 12.4;
    double b = 12.4;
    int c = 12;
    int arr[5] = {1,2,3,4,5};
    //printf("%u", sizeof(c));
    //printf("%u", sizeof(arr));
    //printf("%x", arr);
    int arr1[2][2] = {1,2,3,4};
    printf("%u\n", arr1 );//prints address
    printf("%u", (*arr1 + 1 +(0)));//prints address
}

int binary_s_rec(int x[], int middle, int number, int lower, int highest){
    if (middle == number)
    {
        return middle;
    }
    else if (x[middle] < number)
    {
        binary_s_rec(x,(middle - lower) % 2, number, lower, middle);
    }
    else if (x[middle] > number)
    {
         binary_s_rec(x,(highest - middle) % 2, number, middle, highest);
    }
    
}


int  main() {
   //unsigned long int j = Fact(5);
    //float i = 2;
     //printf("e raised to %f is %lf\n", i , e_x(i));
    //printf("%lf", exp(i));
   //printf("%lf", power(2,12));
    //unsigned int k = Summation_using_recursion(7);
   //printf("\n%i\n", k);
   //int l = power(-4, 5);
   //printf("\n%i", l);
   //prime(25);
  //diamond(5);
  //abc(12);
  //ary_ex2(a, cc);
    //aaary();
    //display_dig(12305);
    //kkkk();
    int a[10] = {11,22,33,44,55,66,77,88,99,110};
    int lowest = 0;
    int highest = 9;
    int middle = (highest - lowest) % 2;
    int number = 44;
    //printf("%i",binary_s_rec(a,middle, number, lowest, highest));
    printf("%i",Summation_using_recursion(10));
 
   return 0;
}

