#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 4
#define size 4

int queue[N];
int front = -1;
int rear = -1;

// Function to enqueue an element at the rear of the double-ended queue
void enqueue_rear(int x)
{
    if ((rear == size - 1 && front == 0) || rear == front - 1)
    {
        printf("Queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

// Function to enqueue an element at the front of the double-ended queue
void enqueue_front(int x)
{
    if ((rear == size - 1 && front == 0) || rear == front - 1)
    {
        printf("Queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = size - 1;
        queue[front] = x;
    }
    else
    {
        front--;
        queue[front] = x;
    }
}

// Function to dequeue an element from the front of the double-ended queue
void dequeue_front()
{
    if (front == -1 || rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }
}

// Function to dequeue an element from the rear of the double-ended queue
void dequeue_rear()
{
    if (front == -1 || rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear = (rear + N - 1) % N;
    }
}

// Function to print the elements of the queue
void print()
{
    int i = front;
    printf("\nFRONT->");
    while (i != rear)
    {
        printf("%i->", queue[i]);
        i = (i + 1) % N;
    }
    printf("%i->", queue[(i + 1) % N]);
    printf("REAR");
}

// A function to demonstrate function pointers and their usage
int funcp()
{
    static int x = 1;
    x++;
    return x;
}

int main()
{
    int x, y;
    x = funcp();
    y = funcp() + x;
    printf("%d\n", (x + y));
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}
