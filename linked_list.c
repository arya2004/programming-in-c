#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

struct node
{
    int data;
    struct node* link;
};

void Main(){
    struct node* head = NULL;
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
    
}

void main(){
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