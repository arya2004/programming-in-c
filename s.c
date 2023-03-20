#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

#define MAX 8
int stack[8];
int top = -1;


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

int main(){
    push(10);
    push(20);
    push(30);
    push(340);
    push(22323);
    push(30213);
    push(10213);
    push(170234);
    push(30);
    printf("top %i\n", peek());
    pop();
    printf("top %i\n", peek());

  return 0;
}


