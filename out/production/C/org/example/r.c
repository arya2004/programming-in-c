#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//#include "linked_list.h"
#include "double_ll.h"
struct q0
{
    int state;
    struct q0* self;
    struct q1* next;
    struct q4* dead;
};
struct q1
{
    int state;
    struct q1* self;
    struct q2* next;
};
struct q2
{
    int state;
    struct q2* self;
    struct q3* next;
};

struct q3
{
    int state;
    struct q3* self;
    struct q0* next;
    
};
struct q4
{
    int state;
    struct q4* self;
    struct q5* next;
    
};

struct q5
{
    int state;
};
struct node* createTape(int *p)
{   struct node* temp = init(temp, *p);
    p++;
    for (int i = 1; i <10 ; i++, p++)
    {
        temp = addNode(temp, *p);
    }
    return temp;
}

void main(){
    
    int p[10] = {4,3,2,5,5,3,4,3,2,5};
    struct node* head = createTape(p);
    struct node* point = head;

    struct q0* zero = (struct q0*)malloc(sizeof(struct q0));
    zero->self = zero;
    zero->state = 0;
    zero->next = (struct q1*)malloc(sizeof(struct q1));
    zero->next->self = zero->next;
    zero->next->state = 1;
    zero->next->next = (struct q2*)malloc(sizeof(struct q2));
    zero->next->next->self = zero->next->next;
    zero->next->next->state = 2;
    zero->next->next->next = (struct q3*)malloc(sizeof(struct q3));
    zero->next->next->next->self = zero->next->next->next;
    zero->next->next->next->state = 3;
    zero->next->next->next->next = zero;
    zero->dead = (struct q4*)malloc(sizeof(struct q4));
    zero->dead->self = zero->dead;
    zero->dead->state = 4;
    zero->dead->next = (struct q5*)malloc(sizeof(struct q5));
    zero->dead->next->state = 5;
    struct q0* rr = zero;
    
    int c = 1;
    while (c != 0)
    {
        if (rr->state == 0 && point->data == 1)
        {
            point->data = 7;
            point = point->next;
            rr = rr->next;
        }
        
        
    }
    

}