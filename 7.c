#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
long int myAtoi(char * s){
    long int r = 0;

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '-' || s[i] == '+') ; i = i + 1){        if(s[i] == '-'){
            r = -r;
        }       if(s[i] <= pow(-2, 31)){
        return -2147483648;
        break;
    }
           else if(s[i] >= pow(2, 31) - 1){
        return 2147483647;
        break;
    }

        else  if(s[i] >= '0' && s[i] <= '9'){
            int j = s[i] - 48;
            r = r*10;
            r = r + a[j];
        }
    }

    return r;
}

void fun(char*s , char* t){
    //   printf("in fun s = %s\n", s);
   // printf("in fun t = %s\n", t); 
    while(*++s);        // takes pointer s to the end of the first string
    while(*s++ = *t++);

   // printf("in fun s = %s\n", s);
   // printf("in fun t = %s\n", t);   //why t has the concatenated array?
                                    //we are assigning t to s (in second for loop) so s should have the concatenated string
}

void pp(int n, char *s,char *t){
    if (n > 0){
      *s = *t;
        pp(n - 1, s =s +1,t = t +1); 
    }
    

}
int Main(void)
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
int *p;
p = arr + num;
    for(i = 0; i < num/2; i++, p = p - 1, arr = arr + 1) {
        int temp = *arr;
        *arr = *p;
        *p = temp;
    }
    
    /* Write the logic to reverse the array. */

//     for(i = 0; i < num; i++)
//         printf("%d ", *(arr + i));
//     return 0;
 }

void two(){
    int a[50] = {1,2,3,4,5,6,7,8,9};
    int pos = 3;
    for(int i = 3; i < 10; ++i){
    a[i] <<= 32;}
        for (int i = 0; i < 10; i++)
    {
        printf("%i\n",a[i]);
    }
    
    a[3] = 88;
    for (int i = 0; i < 10; i++)
    {
        printf("%i\n",a[i]);
    }
    
//hw:insert at last, first, end
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


int main(){
twod();
  return 0;
}


