# C Programming Notes

## Integer Variables

- `int a = 05312;` // Base 8 %o
- `int a = 332u, 01234U;` // Unsigned
- `int b = 0xA;` // Base 16 %x, %p also works
- `int c = 0b1011;` // Binary

## Floating Point Variables

- `float z = 3.4e4;` // Exponent %g

## Printing Format Specifiers

- `printf("%2i",n);` // Change field width specification. Right justification. %3i, %6f, etc., can be used
- `%-2i` // Left justified
- `%.3i` // Displays zeros in blank space. Useful for cashier related shit
- `%.3f` // Prints only 3 decimal places
- `%15.5f` // 15 places reserved for float. 5 places for decimal, 1 for point, and 9 for int part

## Loops and Control Flow

- `for (; i < count; i++, j = j - 10)` // Any field in for loop can be kept blank or even multiple variables can be defined

## Type Casting and Operators

- `(float) a` // Temporarily makes 'a' a float. 'a' becomes its original data type after this. `(int) (double)`
- `==` // Equality test
- `=` // Assignment operator
- `&&` // AND operator
- `||` // INCLUSIVE OR operator

## Characters and Switch Cases

- `'1', '0', '4'` are characters, not numbers
- Use `break` in every switch case. No two case values should be the same

## Ternary Operator and Arrays

- `(condition ? expression_1 : expression_2)` // Ternary Operator. Can be nested
- `int size = sizeof(arr) / sizeof(arr[0]);` // Size of array whose size isn't defined by default

## Functions and Input/Output

- `puts(string)` // Prints the string inside brackets
- `scanf("%50s", s1)` // Reads a string of size under 50 only
- `gets(string)` // Like `scanf("%s", string)`, but includes words with spaces in one string
- `strcpy(name1, name2)` // Copies string name2 to name1. From `#include<string.h>`
- `strcat(destination, source)` // Concatenates string name2 to name1. From `#include<string.h>`
- `int min(int val[100]) { return (min_value); }` // Function to find minimum value

## Variable Scope and Pointers

- Global variables have default initial value zero. Local variables don't have it zero and are set to garbage value.
- To define a global variable, define the variable below `#include<>`
- `fflush(stdin)` // Cleans input buffer before `gets` and after `scanf`
- Pointer declaration and operations explained
- Difference between array and pointer
- Dynamic Memory Allocation (`malloc()`)
- `exit(0)` // Normal program termination
- `exit(1)` // Program failed

## Structs and Bitwise Operators

- Explanation and usage of structs
- Bitwise AND `&`
- Bitwise OR `|`
- Bitwise XOR `^`
- Ones complement `~`
- Left shift `<<`
- Right shift `>>`

## Other Concepts

- Execution starts at `main` function
- Implicit conversion: C converts int to float if int is input for float
- Pass by value: Unless used pointers, local variable in function gets equated to variables in main.
- Comparison of pointers is allowed

## File Operations

- `fopen("", "")` // Opening files
- File pointer operations and file handling
- `feof()` // If end of file reached, returns true
- Text files end with `-1`
- Storing to `.bin` is easier than `.txt`
- Only two functions for `.bin`: `fread()` and `fwrite()`
- `struct student *s[1000]` is an array of pointers to structure

## IEEE Format and Miscellaneous

- IEEE format: 1 bit for sign, 8 for exponent, 23 for base
- Any non-integer constants are double by default

## Pointer Operations

- Pointer variables do not behave as normal variables when operated by various operations
- Only a few operations are allowed for pointers, and they have their own behavior
- Pointer arithmetic and operations explained
- Printing pointers with `printf("%p")`




# Semester 2 Notes

## Abstract Data Structures

### Stack

- `push`: Add to last
- `pop`: Delete last
- `isEmpty`: True if stack is empty, used before pop to check underflow
- `isFull`: True if stack is full, used before push to check overflow
- `peek`: Returns topmost element of stack

### Associativity and Precedence

- Associativity of exponent is right to left
- Operation precedence: `()` > `^` > `*/` > `+-`

## Infix to Postfix Conversion

1. Print the operand as they arrive.
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
3. If the incoming symbol is '(', push it onto the stack.
4. If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
5. If the incoming symbol has higher precedence than the top of the stack, push it onto the stack.
6. If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
7. If the incoming operator has the same precedence with the top of the stack then use the associativity rules.
8. At the end of the expression, pop and print all the operators of the stack.

## Infix to Prefix Conversion

1. Print the operand as they arrive right to left.
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
3. If the incoming symbol is '(', push it onto the stack.
4. If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
5. If the incoming symbol has higher precedence than the top of the stack, push it onto the stack.
6. If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
7. If the incoming operator has the same precedence with the top of the stack then push directly.
8. At the end of the expression, pop and print all the operators of the stack.
9. Reverse the output.

## Queue

- `isFull()`: Rare == size - 1
- `isEmpty()`: Front > Rare or Front == -1
- `enqueue()`: Insert element
- `dequeue()`: Delete from front
- `front()`: Returns front element, initialized as -1
- `rare()`: Returns rare element, initialized as -1
- `size()`: Returns number of elements, Rare - Front + 1
- `display()`: From front to rare printf

## Double Ended Queue

- Elements can be deleted from both front and rare
- Circular array used to represent this
- `enqueue_front()`
- `enqueue_rare()`
- `dequeue_front()`
- `dequeue_rare()`
- `display()`
- `front()`
- `rare()`

## Input and Output Restricted Double Ended Queue

- Input restricted: Enqueue one, dequeue both
- Output restricted: Dequeue one, enqueue both

## Linked List

- [Data, Link]
- End node contains a null pointer

### Insertion & Deletion

Types:
- Simple: [Data, Pointer]
- Doubly: [Pointer to previous address, Data, Pointer to next address]
- Circular: Pointer of last element points to the first element

Notes:
- In C, not mandatory to typecast void pointer
- Linked list is stored in heap memory

### Insertion at Beginning

```c
temp->link = head;
head = ptr;
```



## Stack Definition

```c
typedef struct {
    int count;
    int size;
    int *elements;
} stack;
```
