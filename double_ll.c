#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//#include"linked_list.h"
struct node
{ 
    int data;
    struct node* next;
    struct node* previous;
};

struct node* init(struct node* head, int x )
{    head = (struct node*)malloc(sizeof(struct node*));
    head->next = NULL;
    head->data = x;
    head->previous = NULL;
    return head;
}

struct node* addNode(struct node* head, int x)
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node*));
    temp->next->data = x;
    temp->next->next = NULL;
    temp->next->previous = temp;
    return head;

    
}

int main()
{   
    struct node* head = init(head, 6);
     printf("%i\n", head->data);
     head = addNode(head, 8);
     head = addNode(head, 13);
    head = addNode(head,12);
     printf("%i\n", head->next->data);
     printf("%i\n", head->next->next->data);
     printf("%i\n", head->next->next->next->data);
     printf("%i\n", head->next->previous->data);
}