#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#include"linked_list.h"
struct node
{
    int data;
    struct node* link;
};
struct node* head = NULL;
int length = 0;

struct node* createNode(int x)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = x;
    head->link = NULL;
    length = length+1;
    return head;
}

struct node* addNode(struct node* ,int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->link = NULL;
    head->link = newNode;
    
}



void Main(){

    struct node*newNode;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 20;
    newNode->link = NULL;
    head->link = newNode;

}


void display()
{
        struct node*temp;
    temp = head;
    while (temp->link != NULL)
    {   printf("%i", temp->data);
        temp = temp->link;
    }
    
}

void men(){
    struct node* head = NULL;
    struct node*newNode;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 20;
    newNode->link = NULL;
    head->link = newNode;

    struct node*temp;
    temp = head;
    while (temp->link != NULL)
    {   printf("%i", temp->data);
        temp = temp->link;
    }
    temp->link = newNode;
    

}

struct node* delete()
{
    
}

void main(){
    
    IntLL *list = IntLL_create();
    list = LL_Push(list,10);

}