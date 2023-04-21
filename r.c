#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

struct node
{ 
    int data;
    struct node* link;
};

void declare(){
    
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

void count1(){
    
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
    head->link->link->link = (struct node*)malloc(sizeof(struct node));
    head->link->link->link->data = 26;
    head->link->link->link->link = NULL;
    printf("%i\n", head->link->link->link->data);
    struct node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count = count + 1;
        temp = temp->link;
    }
    printf("%i", count);
}

void count(struct node* head){
    struct node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count = count + 1;
        temp = temp->link;
    }
    printf("%i", count);
}

void print(struct node* head){
    struct node* temp = head;
   
    while(temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->link;
    }
   
}
void insert_end(struct node* head, int x)
{   
    struct node* temp = head;
    while(temp->link!= NULL)
    {  
        temp = temp->link;
    }
    temp->link = (struct node*)malloc(sizeof(struct node));
    temp->link->data= x;
    temp->link->link = NULL;
}

struct node* insert_beginneing(struct node* head, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
    return head;
}

void main(){
    
    struct node* head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 33; 
    head->link = NULL;
    //printf("%i\n", head->data);
    head->link = (struct node*)malloc(sizeof(struct node));
    head->link->data = 66;
    head->link->link = NULL;
   // printf("%i\n", head->link->data);
    head->link->link = (struct node*)malloc(sizeof(struct node));
    head->link->link->data = 16;
    head->link->link->link = NULL;
    //printf("%i\n", head->link->link->data);
    head->link->link->link = (struct node*)malloc(sizeof(struct node));
    head->link->link->link->data = 26;
    head->link->link->link->link = NULL;
    //printf("%i\n", head->link->link->link->data);
    insert_end(head, 4);insert_end(head, 43);
    head = insert_beginneing(head, 99);
   // printf("%i\n", head->data);
    //count(head);
    print(head);
}