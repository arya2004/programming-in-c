#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 10
#include "queue_ll.h"

int main()
{   
    struct node* front = init(front, 6);
    front = insert_end(front,77 );
    front = insert_end(front,34 );
    front = insert_end(front,92 );
    front = print(front);
    front = delete_first(front);
    front = print(front);
}