
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

#define N 5
#define size 5
int queue[N];
int front=-1;
int rare= -1;
//double ended queur
void enqueue_rare(int x)
{
    if ((rare == size -1 && front == 0 )|| rare == front - 1 )
    {
        printf("size full");
    }
    else if (front == -1 && rare == -1)
    {
        front = 0;
        rare = 0;
        queue[rare] = x;
    }
    else if (rare == size-1)
    {
        rare = 0;
        queue[rare] = x;
    }
    

    else
    {
        rare = (rare+ 1)% N ;
        queue[rare] = x;
    }
    
}

void enqueue_fornt(int x)
{
    if ((rare == size -1 && front == 0 )|| rare == front - 1 )
    {
        printf("size full");
    }
    else if (front == -1 && rare == -1)
    {
        front = 0;
        rare = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = size - 1;
        queue[front] = x;
    }
    

    else
    {
        front-- ;
        queue[front] = x;
    }
    
}

void dequeue_front()
{
    if (front == -1 || rare == -1)
    {
        printf("empty");
    }
    else if (front == rare)
    {
        front = -1;
        rare = -1;
    }
    else
    {
        front = (front + 1)% N;
    }
}
void dequeue_rare()
{
    if (front == -1 || rare == -1)
    {
        printf("empty");
    }
    else if (front == rare)
    {
        front = -1;
        rare = -1;
    }
    else
    {
        rare = (rare + N - 1)% N;
    }
}

void print()
{
    int i = front;
    while (i != rare)
    {
        printf("%i", queue[i]);
        i = (i + 1)% N;
    }
    
}
//pass addres of members of structures and printn them
int main(){


  return 0;
}