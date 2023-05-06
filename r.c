#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//#include "linked_list.h"

struct node
{
    int data;
    struct node* self;
    struct node* next;
};


void main(){
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->self = head;
    head->data = 10;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 80;
    head->next->self = head->next;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 55;
    head->next->next->self = head->next->next;
    head->next->next->next = head;
    printf("\n%i", head->data);
    printf("\n%i", head->self->data);
    printf("\n%i", head->next->data);
    printf("\n%i", head->next->self->data);
    printf("\n%i", head->next->next->data);
    printf("\n%i", head->next->next->next->data);
    printf("\n%i", head->next->next->next->next->data);
    printf("\n%i", head->next->next->next->next->next->data);
   
}