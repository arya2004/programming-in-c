#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

struct node
{ 
    int data;
    struct node* link;
};

struct node * init(struct node* head,int x)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = x; 
    head->link = NULL;
    return head;
}

struct node*count(struct node* head){
    struct node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count = count + 1;
        temp = temp->link;
    }
    printf("\n%i", count);
    return head;
}

struct node* print(struct node* head){
    struct node* temp = head;
   printf("\nTOP");
    while(temp != NULL)
    {
        printf("\n\\|/\n %i", temp->data);
        temp = temp->link;
    }
   return head;
}


struct node* push(struct node* head, int x)
{   //we are passing the address of first node but we also need address of head
    //alternatively pass &head and use double pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
    return head;
}


struct node* pop(struct node* head)
{
    struct node* temp = head;
    head = head->link;
    free(temp);
    temp = NULL;//without this, temp still contains address of first location
    return head;
}

struct node* drop_stack(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
    
}


