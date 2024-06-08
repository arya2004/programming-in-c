#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ANSI color codes for terminal output
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Structure to hold the todo list
typedef struct TODO {
    char data[100][100];  // Array to store todo items
    int index;            // Current number of todo items
} todo;

/**
 * @brief Creates a new todo list.
 * 
 * @return Pointer to the newly created todo list.
 */
todo *createTodo(void) {
    todo *newTodo = malloc(sizeof(todo));
    if (newTodo == NULL) {
        fprintf(stderr, "Failed to allocate memory for new todo list.\n");
        exit(EXIT_FAILURE);
    }
    newTodo->index = 0;
    return newTodo;
}

/**
 * @brief Adds a new item to the todo list.
 * 
 * @param newTodo Pointer to the todo list.
 */
void addTodo(todo *newTodo) {
    if (newTodo->index >= 100) {
        printf("%sTodo list is full. Cannot add more items.%s\n", RED, RESET);
        return;
    }
    char input[100];
    printf("%sEnter a new item: %s\t", YELLOW, RESET);
    fgets(input, sizeof(input), stdin);
    strcpy(newTodo->data[newTodo->index], input);
    newTodo->index++;
}

/**
 * @brief Removes an item from the todo list.
 * 
 * @param newTodo Pointer to the todo list.
 */
void removeTodo(todo *newTodo) {
    int targetIndex;
    printf("%sEnter the number of the todo you want to remove: %s", YELLOW, RESET);
    scanf("%d", &targetIndex);
    getchar(); // To consume the newline character left by scanf

    if (targetIndex > 0 && targetIndex <= newTodo->index) {
        for (int i = targetIndex; i < newTodo->index; ++i) {
            strcpy(newTodo->data[i - 1], newTodo->data[i]);
        }
        newTodo->index--;
    } else {
        printf("%sNo todo is present at this number.%s\n", RED, RESET);
    }
}

/**
 * @brief Displays all items in the todo list.
 * 
 * @param newTodo Pointer to the todo list.
 */
void displayTodo(todo *newTodo) {
    for (int i = 0; i < newTodo->index; ++i) {
        printf("%s%d.\t%s%s%s", MAGENTA, i + 1, BLUE, newTodo->data[i], RESET);
    }
}

/**
 * @brief Main function to handle the todo list operations.
 */
int main() {
    char input[100];
    bool endOfLoop = false;
    todo *myTodo = createTodo();

    while (!endOfLoop) {
        printf("%sAdd (a), Remove (r), Display (d), or Quit (q): %s", CYAN, RESET);
        fgets(input, sizeof(input), stdin);
        
        switch (input[0]) {
            case 'a':
                addTodo(myTodo);
                break;
            case 'r':
                removeTodo(myTodo);
                system("clear"); // Clear the screen after removing an item
                break;
            case 'd':
                displayTodo(myTodo);
                break;
            case 'q':
                printf("%sExiting...%s\n", RED, RESET);
                endOfLoop = true;
                break;
            default:
                printf("%sPlease enter only 'a' (Add), 'r' (Remove), 'd' (Display), or 'q' (Quit).\n%s", RED, RESET);
        }
    }

    free(myTodo); // Free allocated memory
    return 0;
}
