#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* link;
};

// Function to initialize a linked list with a given value
struct Node* init(struct Node* head, int x) {
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->link = NULL;
    return head;
}

// Function to count the number of nodes in the linked list
struct Node* count(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    printf("\nNumber of nodes: %d", count);
    return head;
}

// Function to print the elements of the linked list
struct Node* print(struct Node* head) {
    struct Node* temp = head;
    printf("\nHEAD");
    while (temp != NULL) {
        printf(" -> %d", temp->data);
        temp = temp->link;
    }
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insert_end(struct Node* head, int x) {
    struct Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = (struct Node*)malloc(sizeof(struct Node));
    temp->link->data = x;
    temp->link->link = NULL;
    return head;
}

// Function to insert a node at the beginning of the linked list
struct Node* insert_beginning(struct Node* head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = head;
    head = temp;
    return head;
}

// Function to insert a node at a specific position in the linked list
struct Node* insert_any(struct Node* head, int pos, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;
    struct Node* ptr = head;
    for (int i = 1; i < pos - 1; i++) {
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return head;
}

// Function to delete the first node of the linked list
struct Node* delete_first(struct Node* head) {
    struct Node* temp = head;
    head = head->link;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
struct Node* delete_last(struct Node* head) {
    struct Node* sec_last = head;
    while (sec_last->link->link != NULL) {
        sec_last = sec_last->link;
    }
    free(sec_last->link);
    sec_last->link = NULL;
    return head;
}

// Function to delete a node at a specific position in the linked list
struct Node* delete_any(struct Node* head, int pos) {
    struct Node* current = head;
    struct Node* previous = head;
    for (int i = 2; i < pos; i++) {
        previous = previous->link;
    }
    current = previous->link;
    previous->link = current->link;
    free(current);
    return head;
}

// Function to delete the entire linked list and free memory
struct Node* drop_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
    return NULL;  // Return NULL as the list is empty after dropping
}

// Function to reverse the linked list
static void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;  // Initialize the head pointer

    // Example usage: creating a linked list and performing operations
    head = init(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 4);
    head = insert_beginning(head, 0);
    head = insert_any(head, 3, 2);  // Inserting '2' at position 3
    head = delete_first(head);
    head = delete_last(head);
    head = delete_any(head, 2);  // Deleting node at position 2
    head = reverse(&head);

    // Printing the modified linked list
    printf("Modified Linked List:");
    head = print(head);

    // Dropping the linked list and freeing memory
    head = drop_list(head);

    return 0;
}
