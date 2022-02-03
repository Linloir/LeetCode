//C Solution (2) to Leetcode.138

//Description:
//In the first traversal, every copied node is inserted after the original one
//In the second traversal, the random field of copied nodes is setted according to its previous node's random field's succeeed node
//In the second traversal, the copied list and the original list is seperated and the next fields of both lists are set

//Note:
//In this solution, the price of maintaining the original list leads to an extra traverse
//Solution with two traversal see: [C_Solution_2_Opt.c]

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
    for(struct Node* ptr = head; ptr != NULL; ptr = ptr->next){
        ptr->next->random = ptr->random ? ptr->random->next : NULL;
        ptr = ptr->next;
    }
    //Third Traversal
    struct Node* cpyHead = head->next;
    struct Node* ptr_cpy = cpyHead;
    struct Node* ptr_orig = head->next;
    while(ptr_orig->next != NULL){
        ptr_cpy->next = ptr_orig->next;
        ptr_orig->next = ptr_orig->next->next;
        ptr_orig = ptr_orig->next;
        ptr_cpy = ptr_cpy->next;
    }
    return cpyHead;
}