#include <stdio.h>

// Function to swap two integers using pointers
void swapIntegers(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Function to calculate power recursively
double power(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

// Function to insert an element at the end of an array and shift elements
void insertAndShift(int array[], int size, int position, int value) {
    if (position < 0 || position >= size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = size - 1; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
}

// Function to define the structure of an employee
void defineEmployeeStruct() {
    struct Employee {
        char name[20];
        char surname[20];
        int experience;
        float salary;
    };
}

// Queue functions for enqueue, dequeue, display, and peek operations
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        front++;
    }
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%i ", queue[i]);
        }
        printf("\n");
    }
}

void peekQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %i\n", queue[front]);
    }
}

int main() {
    // Example usage of functions can be added here
    return 0;
}
