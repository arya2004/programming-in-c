#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#include <limits.h>
int noos = 0;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1){
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int toh(int n, char s,char d, char v){  //n disk ,from source S to destination D via V
    static int a = 0;
    if (n > 0)
    {
        toh(n-1, s, v,d); //move n-1 disk, from source S to destination V to via D
        printf("\n%c to %c", s, d); // move nth disk from source S to destinatin D
        toh(n-1, v,d,s);//move n-1 disk, from source V to destination D to via S
        a = a + 1;
    }
    return(a);
}

void a(int dollar, int cant){
    for ( int count = 1; count <= 10; ++count)
    {
        printf("$%.5i.%.2i\n\n",dollar, cant);
    }
    
} 

void leap(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0)
    {
        printf("Leap1");
    }
    else if (year % 4 == 0 && year % 400 == 0)
    {
        printf("Leap2");
    }// if a leap y is divisible by 100 then it should also be divisible by 400
    else{
        printf("NOt");
}
}


void q(int a){
    if (0)
    {
        printf("%i",a);
    }
    
}

void w(float a, float b){
    if (b == 0)
    {
        printf("You are disgrace");
    }
    else{
        printf("%.3f", a / b);

}
}

 void print_num_word(int dividend){
    int quotient1;       // 342 prints three four two
    int remainder1;
    int nod1 = 0;
    int dividend1 = dividend;
    int dividend2 = dividend;
while (dividend1 != 0){
      quotient1 = dividend1 / 10;
      remainder1 = dividend1 % 10;
      nod1 = nod1 + 1;
      dividend1 = quotient1;
}
//above calculated number of digits
    
    int quotient2;       // 342 prints three four two
    int remainder2;
    int nod = 0;
    int ten = 1;
for (; (nod1 -1) > 0; nod1 = nod1 - 1){
    ten = ten * 10;
}
    //above calculated dividor
for (;ten >= 1 ;){
    quotient2 = dividend2 / ten;
    remainder2 = dividend2 % ten;
    dividend2 = remainder2;
    ten = ten / 10;
switch(quotient2){
    case 1	:
        printf("ONE ");
        break;
    case 2	:
        printf("TWO ");
        break;
    case 3	:
        printf("THREE ");
        break;
    case 4	:
        printf("FOUR ");
        break;
    case 5	:
        printf("FIVE ");
        break;
    case 6	:
        printf("SIX ");
        break;
    case 7	:
        printf("SEVEN ");
        break;
    case 8	:
        printf("EIGHT ");
        break;
    case 9	:
        printf("NINE ");
        break;
    case 0	:
        printf("ZERO ");
        break;
}
}
}   
//instead of all the above  DogShit, store the remainder in array reversed. so theyy are stored in array correctly. NO need of that 'ten' BS

void ltrname(char b[]){
    int i = 0;
    for (; b[i]; i++){;
    }
    printf("%i", i);
}

/*void ltrcopy(char b[], char c[]){
    int size = sizeof(b) / sizeof(b[0]);
    printf("%i", size);   
    for (int i = 0; i < size ;i = i + 1){
        c[i] = b[i];
    }
    c[size] = 0;
    puts(c);

}*/

void ltrcon(char b[], char c[]){
  char z[] = " ";
  strcat(b, z);
  strcat(b, c);
  puts(b);

}

/*void ltrconmanual(char b[], char c[]){
    int size = sizeof(b) / sizeof(b[0]);  
    for (int i = 0; c[i] ;i = i + 1){
        b[size + i] = c[i];
    }
    
    puts(b);

}*/

void auto_stat(void){
    int a = 1;  //difference btwn normal var and static var
    static int b = 1;
    printf("automatic var: %i", a);
    printf("  static var: %i", b);
    printf("\n");
    a = a + 1;
    b = b + 1;
}

/*void ff(void){
    struct day {
        int date;
        int month;
        int year;
    }
    //struct day bday;
}*/


int display_dig(int n){
    if (n > 0){
        display_dig(n/10);
        return(n%10);
        
        
    }
    
}

float rr(int a)
{
    if (a == 1)
    {
        return 4;
    }
    else
    {
        return (5*a) + rr(a-1);
    }
    
    
}





void rotate(int* nums, int numsSize, int k){
    for (int i = 0; i < k; i++)
    {   int j = nums[numsSize -1];
        nums--;
        realloc(nums, sizeof(int) * numsSize);
        nums[0] = j;
    }
        for (int ii = 0; ii < 5; ii++)
    {
        printf("\n%i", nums[ii]);
    }
        
}

void fibf(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = num-i-1; j >= 0 ; j--)
        {
           printf(" ");
        }
        for (int k = 0; k < (2*i) +1 ; k++)
        {
           if( k%2 == 0)
           {
                printf("%c", i+65);
           }
           if( k%2 == 1)
           {
                printf(" ");
           }
           
        }
        printf("\n");
        
        
    }
    
}

void parallegram(int length, int height)
{
    for (int i = 1; i < height; i++)
    {
        for (int k = 0; k < height -i; k++)
        {
            printf("_");
        }
        if(i == 0 || i== height -1 )
        {
            for (int j = 0; i < length; j++)
            {
                printf("%i",j);
            }
            
        }
        if(!(i == 0 || i== height -1) )
        {
            printf("*");
            for (int ii = 0; ii < length -2; ii++)
            {
                printf("_");
            }
            

            printf("*");
        }
        printf("\n");
        
    }
    
}


int main(){ 
   // printf("\n%i",toh(3, 'A', 'C', 'B'));
    
    //print_num_word(7654635);
    //printf("Name:");
    //scanf("%s",name1);s
    //auto_stat();
    //display_dig(345);
  // printf("%f", rr(64));
  //printf("%f", TT(4));
  //rotate();
    //printf("%d",ddm(2022,9,3));
   // fibf(10);
//printf("%i", 'A');
     parallegram(4,9);
    return 0;
}
