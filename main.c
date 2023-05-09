#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 10
//#include "queue_ll.h"

void hello(){
    int i = 0;
    int n =10;
    for ( ; i < n; i++)
    {
        
    }
    printf("%i",i);
}

typedef struct{
    int n;
    int *a;
}stack;

stack init(stack base,int c){
    base.n = c;
    base.a = (int *)malloc(sizeof(int)*c);
    return base;
}


int main()
{   
    // struct node* front = init(front, 6);
    // front = enqueue(front, 90);
    // front = enqueue(front, 34);
    // front = enqueue(front, 52);
    // front = enqueue(front, 12);
    // front = print(front);
    //     front = dequeue(front);
    // front = dequeue(front);
    // front = print(front);
    // front  = enqueue(front, 77);
    // front = print(front);
    stack s = init(s, 5);
    s.a[0] = 44;
    s.a[1] = 45;
    s.a[2] = 46;
    s.a[3] = 47;
    s.a[4] = 48;s.a[5] = 48;
    printf("\n%i", s.a[0]);printf("\n%i", s.a[1]);printf("\n%i", s.a[2]);printf("\n%i", s.a[3]);printf("\n%i", s.a[4]);printf("\n%i", s.a[5]);printf("\n%i", s.a[6]);
    
}