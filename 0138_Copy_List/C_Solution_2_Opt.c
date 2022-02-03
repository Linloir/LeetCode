//Note:
//In this solution, the orignal list is modified in order to cut down one traversal
//Solution with three traversal see: [C_Solution_2.c]

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head){
    if(!head){
        return NULL;
    }
    //First Traversal
    for(struct Node* ptr = head; ptr != NULL; ptr = ptr->next){
        struct Node* copied = (struct Node*)malloc(sizeof(struct Node));
        copied->next = ptr->next;
        copied->val = ptr->val;
        ptr->next = copied;
        ptr = copied;
    }
    //Second Traversal
    for(struct Node* ptr = head; ptr != NULL; ){
        struct Node* copied = ptr->next;
        copied->random = ptr->random ? ptr->random->next : NULL;
        ptr = copied->next;
        copied->next = ptr ? ptr->next : NULL;
    }
    return head->next;
}