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
   printf("\nHEAD");
    while(temp != NULL)
    {
        printf("->%i", temp->data);
        temp = temp->link;
    }
   return head;
}
struct node*insert_end(struct node* head, int x)
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

struct node* insert_beginneing(struct node* head, int x)
{   //we are passing the address of first node but we also need address of head
    //alternatively pass &head and use double pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
    return head;
}

struct node*insert_any(struct node* head, int pos, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node* ptr = head;
    for (int i = 1;i<pos-1 ; i++)
    {
       ptr = ptr->link;
    }//order imp, else access to 3rd element is lost
    temp->link = ptr->link;
    ptr->link = temp;
return head;

}

struct node* delete_first(struct node* head)
{
    struct node* temp = head;
    head = head->link;
    free(temp);
    temp = NULL;//without this, temp still contains address of first location
    return head;
}

// void delete_last(struct node* head)
// {   //if no node, list empty
// //if head->link = NUNLL, no node, free head
//     struct node* last = head;
//     struct node* sec_last = head;
//     while (last->link != NULL)
//     {
//         sec_last = last;
//         last = last->link;
//     }
//     sec_last->link = NULL;
//     free(last);
//     last = NULL;
// }

 struct node* delete_last(struct node* head)
{   //if head = NULL, list empty
//if head->link = NUNLL, no node, free head
    
    struct node* sec_last = head;
    while (sec_last->link->link != NULL)
    {
        sec_last = sec_last->link;
    }
    free(sec_last->link);
    sec_last->link = NULL;
    return head;
}

struct node*delete_any(struct node* head, int pos)
{
    struct node* current = head;
    struct node* previous = head;
    for (int i = 2; i < pos; i++)
    {
        previous = previous->link;
    }
    current = previous->link;
    previous->link = current->link;
    free(current);
    return head;
    
}

struct node* drop_list(struct node* head)
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


// static void reverse(struct Node** head_ref)
// {
//     struct Node* prev = NULL;
//     struct Node* current = *head_ref;
//     struct Node* next = NULL;
//     while (current != NULL) {
//         // Store next
//         next = current->next;
 
//         // Reverse current node's pointer
//         current->next = prev;
 
//         // Move pointers one position ahead.
//         prev = current;
//         current = next;
//     }
//     *head_ref = prev;
// }