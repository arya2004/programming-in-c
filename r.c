#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

struct node
{ 
    int data;
    struct node* link;
};

void main(){
    
    struct node* head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 33; 
    head->link = NULL;
    printf("%i\n", head->data);
    head->link = (struct node*)malloc(sizeof(struct node));
    head->link->data = 66;
    head->link->link = NULL;
    printf("%i\n", head->link->data);
        head->link->link = (struct node*)malloc(sizeof(struct node));
    head->link->link->data = 16;
    head->link->link->link = NULL;
    printf("%i\n", head->link->link->data);
}