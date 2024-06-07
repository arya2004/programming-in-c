#include <stdio.h>
#include <stdlib.h>

struct node
{ 
    int data;
    struct node* next;
    struct node* previous;
};

/**
 * @brief Initialize the linked list with a head node containing the given data.
 * 
 * @param head Pointer to the head node of the linked list.
 * @param x Data to be stored in the head node.
 * @return struct node* Pointer to the initialized linked list.
 */
struct node* init(struct node* head, int x)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = x;
    head->previous = NULL;
    return head;
}

/**
 * @brief Add a new node at the end of the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @param x Data to be stored in the new node.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* addNode(struct node* head, int x)
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->data = x;
    temp->next->next = NULL;
    temp->next->previous = temp;
    return head;
}

/**
 * @brief Add a new node at the beginning of the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @param x Data to be stored in the new node.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* addBeginning(struct node* head, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = head;
    head->previous = temp;
    temp->data = x;
    temp->previous = NULL;
    head = temp;
    return head;
}

/**
 * @brief Add a new node at a specific position in the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @param pos Position at which to add the new node.
 * @param x Data to be stored in the new node.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* addAny(struct node* head, int pos, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node* ptr = head;
    for (int i = 2; i < pos; i++)
    {
        ptr = ptr->next;
    }
    ptr->next->previous = temp;
    temp->next = ptr->next;
    temp->previous = ptr;
    ptr->next = temp;
    return head;
}

/**
 * @brief Delete the first node in the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* deleteBeginning(struct node* head)
{
    head = head->next;
    free(head->previous);
    head->previous = NULL;
    return head;
}

/**
 * @brief Delete the last node in the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* deleteNode(struct node* head)
{
    struct node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

/**
 * @brief Delete a node at a specific position in the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * @param pos Position of the node to be deleted.
 * @return struct node* Pointer to the updated linked list.
 */
struct node* deleteAny(struct node* head, int pos)
{
    struct node* temp = head;
    for (int i = 2; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next->previous);
    temp->next->previous = temp;
    return head;
}

/**
 * @brief Print the linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 */
void printLL(struct node* head)
{
    struct node* temp = head;
    printf("\nHEAD");
    while (temp != NULL)
    {
        printf("<=>%i", temp->data);
        temp = temp->next;
    }
}

/**
 * @brief Main function to demonstrate linked list operations.
 * 
 * @return int Exit code.
 */
int main()
{
    struct node* head = NULL; // Initialize head pointer
    head = init(head, 6);
    head = addNode(head, 8);
    head = addNode(head, 13);
    head = addNode(head, 12);
    head = addNode(head, 16);
    head = addNode(head, 90);
    head = addNode(head, 91);
    printLL(head);
    head = deleteBeginning(head);
    printLL(head);
    head = deleteNode(head);
    printLL(head);
    head = deleteAny(head, 4);
    printLL(head);
    return 0;
}
