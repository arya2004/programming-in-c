#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 8

int stack[MAX];
int top = -1;

// Function to initialize the stack
void init()
{
    top = -1;
}

// Function to check if the stack is full
int isFull()
{
    return top == MAX - 1 ? 1 : 0;
}

// Function to check if the stack is empty
int isEmpty()
{
    return top == -1 ? 1 : 0;
}

// Function to peek at the top element of the stack
int peek()
{
    return stack[top];
}

// Function to push an element onto the stack
void push(int x)
{
    if (!isFull())
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("Overflow\n");
    }
}

// Function to pop an element from the stack
void pop()
{
    if (!isEmpty())
    {
        top--;
    }
    else
    {
        printf("Underflow\n");
    }
}

// Function to display the elements of the stack
void display()
{
    for (int w = 0; w <= top; w++)
    {
        printf("%i ", stack[w]);
    }
    printf("\n");
}
