#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 10
#include "stack.h"

void sswitch()
{   int ooo = 0;
    int g = 1;
    int choice;
    while (g != 0)
    {
        printf("\n give your choice\n0)quit\t1)init\t2)isFull\t3)isEmpty\t4)Peek\t5)Push\t6)Pop\t7)display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                init();
                break;
            case 2:
                printf("%i",isFull());    
                break;
            case 3:
                 printf("%i", isEmpty());
                break;
            case 4:
                printf("%i", peek());
                break;
            case 5:
                printf("eNTER INTEGER: ");
                scanf("%i", &ooo);
                push(ooo);
                break;
               
            case 6:
                pop();
                break;
            case 7:
                display();
            case 0:
                g = 0;
        }

    }
}

int main()
{   push(5);push(8);push(234);push(5);push(8);push(234);push(5);push(8);push(234);push(5);push(8);push(234);
        push(2);pop();display();

}