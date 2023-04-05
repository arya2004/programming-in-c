
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

#define N 5
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

void dequeue()
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

int main(){
int i = 0;


  return 0;
}