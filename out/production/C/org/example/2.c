#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//2 var switch with xor
void a(void){
    int a = 77;
    int b = 55;
    printf("%i, %i\n", a,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%i, %i\n", a,b);
}
//2s compliment
void b(void){
    int a = 77;
    int b = 5;
    printf("%i\n", a);
    a = ~a;
    a = a + 1;
    printf("%i\n", a);
}

struct date1{
    int d,m,y;
};

struct date2{
    unsigned int d : 5;
    unsigned int m : 4;
    int y : 12;
};
struct aa{
int x;
char y;
char y1;
char y2;
char y3;
char y4;
double z;
};
union a{
int x;
char y;
double z;
};

void bin(int n){
    if (n > 0){
        bin(n/2);
        if (n % 2 == 1){
            printf("1");
        }
        if (n % 2 == 0){
            printf("0");
        }
    }
}
int main(){
    struct date1 dob;
    dob.d = 8;
    dob.m = 1;
    dob.y = 198;

    int z;
    //printf("%i\n", sizeof(z));
   // printf("%i\n",dob.d );
   // printf("%i\n",dob.m);
    //printf("%i\n", dob.y);
   //printf("%i", sizeof(union a));
   //bin('e');
   
    return 0;
}