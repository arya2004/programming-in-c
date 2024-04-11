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
   printf("\nFRONT");
    while(temp != NULL)
    {
        printf("->%i", temp->data);
        temp = temp->link;
    }
    printf("->REAR");
   return head;
}
struct node*enqueue(struct node* head, int x)
{   
    struct node* temp = head;
    while(temp->link!= NULL)
    {  
        temp = temp->link;
    }
    temp->link = (struct node*)malloc(sizeof(struct node));
    temp->link->data= x;
    temp->link->link = NULL;
    return head;
}



struct node* dequeue(struct node* head)
{
    struct node* temp = head;
    head = head->link;
    free(temp);
    temp = NULL;//without this, temp still contains address of first location
    return head;
}



struct node* drop_queue(struct node* head)
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
