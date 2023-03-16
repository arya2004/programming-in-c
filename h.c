#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//swpa pointer, recurs power, del in array, struct emp:assign 
void swapp(int *a, int *b){     //int a = 12;int b = 13;
                //printf("%i %i", a, b);
    *a = *b + *a;                    //swapp(&a, &b);
                   //printf("%i %i", a, b);
}
double power(double a, unsigned int n ) {
    if(n == 0) {
        return 1;
    }
    else{
        return a * power(a , n-1);
    }
}

void last(){
    int a[10] = {2,4,6,8,10,12,14,16,18};
    int size = 10;
    int pos = 7;
    int digit = 32;
    for (int i = size; i > pos; i = i - 1)
    {
        a[i] = a[i-1];
    }
    a[pos] = 32;
    for (int ii = 0; ii < size; ii++)
    {
        printf("%i\n",a[ii]);
    }
    
    
}

void a1(){
    struct employee
    {   char name[20];
        char surname[20];
        int experience;
        float salary;
        
    };
    

}



int main(){
int i = 0;
for (printf("%i",power(10)); i < 2; i++)
{
  
}


  return 0;
}