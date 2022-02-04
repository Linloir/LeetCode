#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* ptr_t = dummyHead;
    while(ptr_t->next){
        struct ListNode* ptr_s = dummyHead;
        while(ptr_s != ptr_t && ptr_s->next->val <= ptr_t->next->val){
            ptr_s = ptr_s->next;
        }
        struct ListNode* temp = ptr_t->next;
        ptr_t->next = ptr_t->next->next;
        temp->next = ptr_s->next;
        ptr_s->next = temp;
        if(ptr_t == ptr_s){
            ptr_t = ptr_t->next;
        }
    }
    ptr_t = dummyHead->next;
    free(dummyHead);
    return ptr_t;
}