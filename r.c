#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#include "linked_list.h"

void main(){
    
    struct node* head = init(head,44);
   head = insert_end(head, 23);
   head = insert_end(head, 77);
    head = insert_end(head, 24);
   head = insert_end(head, 83);
   head = insert_end(head, 90);
   head = insert_end(head, 111);
   head = delete_first(head);
   print(head);
   head = drop_list(head);
   print(head);
    
}