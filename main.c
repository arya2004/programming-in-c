#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 10
#include "queue_ll.h"

int main()
{   
    struct node* front = init(front, 6);
    front = enqueue(front, 90);
    front = enqueue(front, 34);
    front = enqueue(front, 52);
    front = enqueue(front, 12);
    front = print(front);
        front = dequeue(front);
    front = dequeue(front);
    front = print(front);
    front  = enqueue(front, 77);
    front = print(front);
}