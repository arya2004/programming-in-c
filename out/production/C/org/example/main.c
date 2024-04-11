#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 10
//#include "queue_ll.h"
//#include "linked_list.h"
void hello(){
    int i = 0;
    int n =10;
    for ( ; i < n; i++)
    {
        
    }
    printf("%i",i);
}

struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* j = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* jj = j;
    jj->next = NULL;
    jj.val = 0;
    while (l1 != NULL && l2 != NULL)
    {
        if (jj->val +l1->val + l2->val <= 9)
        {
            jj->val = jj->val +  l1->val + l2->val;
                    l1 = l1->next; l2 = l2->next;
            
        jj = (struct ListNode*)malloc(sizeof(struct ListNode));
        jj = jj->next;

        }
        else if (jj->val +l1->val + l2->val > 9)
        {   
            jj->val = (jj->val +  l1->val + l2->val) % 10;
            l1 = l1->next; l2 = l2->next;
            jj = (struct ListNode*)malloc(sizeof(struct ListNode));
            jj = jj->next;
            jj->val = 1;
        }

    }
    
    return j;
}

int main()
{   struct ListNode* l1; struct ListNode* l2;
    addTwoNumbers(l1,l2);
 
}