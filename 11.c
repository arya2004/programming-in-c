#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define reset "\x1B[0m"
#define red "\x1B[31m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan "\x1B[36m"
#define white "\x1B[37m"

typedef struct TODO {
    char data[100][100];
    int index;
} todo;

todo *createTodo(void) {
    todo *newTodo = malloc(sizeof(todo));
    newTodo->index = 0;
    return newTodo;
}

void addTodo(todo *newTodo) {
    char input[100];
    printf("%sEnter a new item :%s\t", yellow, reset);
    fgets(input, 100, stdin);
    strcpy(newTodo->data[newTodo->index], input);
    newTodo->index++;
}

void removeTodo(todo *newTodo) {
    int targetIndex;
    printf("%sEnter the number of the todo you want to remove :\t%s", yellow, reset);
    scanf("%d", &targetIndex);
    if (targetIndex >= 0 && targetIndex <= newTodo->index) {
        for (int i = targetIndex; i < newTodo->index; ++i) {
            strcpy(newTodo->data[i - 1], newTodo->data[i]);
        }
        newTodo->index--;
    } else {
        printf("%sNo todo is present at this number%s\n", red, reset);
    }
}

void displayTodo(todo *newTodo) {
    for (int i = 0; i < newTodo->index; ++i) {
        printf("%s%d.\t%s%s%s", magenta, (i + 1), blue, newTodo->data[i], reset);
    }
}

void main() {
    char input[100];
    bool endOfLoop = false;
    todo *myTodo = createTodo();
    while (!endOfLoop) {
        printf("%sa%sdd,%sr%semove,%sd%sisplay or %sq%suit :\t%s", cyan, green, cyan, green, cyan, green, cyan, green,
               reset);
        fgets(input, 100, stdin);
        switch (*input) {
            case 'a':
                addTodo(myTodo);
                break;
            case 'r':
                removeTodo(myTodo);
                getchar();
                system("clear");
                break;
            case 'd':
                displayTodo(myTodo);
                break;
            case 'q':
                printf("%sexit()%s", red, reset);
                endOfLoop = true;
                break;
            default:
                printf("%sPlease enter only %sa%sdd,%sr%semove,%sd%sisplay or %sq%suit\n%s", red, cyan, red, cyan,
                       red, cyan, red, cyan, red, reset);
        }
    }
}