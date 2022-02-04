//Solution 1
//Description:
//Two traversal used
//In the first traversal, orignal list is seperated alternately into two lists
//In the second traversal, the two lists is merged into the result list

#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

void reorderList(struct ListNode* head){
    //declaration of new list heads
    struct ListNode* list_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list_1->next = NULL;
    list_2->next = NULL;
    //first traversal
    struct ListNode* ptr = head;
    struct ListNode* ptr_1 = list_1;
    struct ListNode* ptr_2 = list_2;
    while(ptr){
        ptr_1->next = ptr;
        ptr_1 = ptr_1->next;
        ptr_1->next = NULL;
        ptr = ptr->next;
        ptr_2->next = ptr;
        ptr_2 = ptr_2->next;
        if(ptr_2){
            ptr_2->next = NULL;
            ptr = ptr->next;
        }
    }
    //second traversal
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;
}