#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* previous;
};

// Function to initialize the linked list with a single node
struct node* init(struct node* head, int x) {
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = x;
    head->previous = NULL;
    return head;
}

// Function to add a node at the end of the linked list
struct node* addNode(struct node* head, int x) {
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->data = x;
    temp->next->next = NULL;
    temp->next->previous = temp;
    return head;
}

// Function to add a node at the beginning of the linked list
struct node* addBeginning(struct node* head, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = head;
    head->previous = temp;
    temp->data = x;
    temp->previous = NULL;
    head = temp;
    return head;
}

// Function to add a node at a specific position in the linked list
struct node* addAny(struct node* head, int pos, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node* ptr = head;
    for (int i = 2; i < pos; i++) {
        ptr = ptr->next;
    }
    ptr->next->previous = temp;
    temp->next = ptr->next;
    temp->previous = ptr;
    ptr->next = temp;
    return head;
}

// Function to delete the first node in the linked list
struct node* deleteBeginning(struct node* head) {
    head = head->next;
    free(head->previous);
    head->previous = NULL;
    return head;
}

// Function to delete the last node in the linked list
struct node* deleteNode(struct node* head) {
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a specific position in the linked list
struct node* deleteAny(struct node* head, int pos) {
    struct node* temp = head;
    for (int i = 2; i < pos; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next->previous);
    temp->next->previous = temp;
    return head;
}

// Function to print the linked list
void printLL(struct node* head) {
    struct node* temp = head;
    printf("\nHEAD");
    while (temp != NULL) {
        printf("<=>%i", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = init(head, 6);
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
