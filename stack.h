#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

#define MAX 8
int stack[MAX];
int top = -1;
int qq = 0;
void init(){
    top = -1;
}

int isFull(){
    if (top == MAX -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if (top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    return stack[top];
}


void push(int x){
    if (!isFull())
    {
        top = top + 1;
        stack[top] = x;
    }
    else{
        printf("Overflow\n");
    }
    
}

void pop(){
    if (!isEmpty())
    {   int x = stack[top];
        top = top - 1;
        
    }
    else{
        printf("underflow\n");
    }
    
}

void display(){
    for (int w = 0 ; w <= top; w = w+1)
    {
        printf("%i ", stack[w]);
    }
    printf("\n");
}




