#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

struct ListNode* detectCycle(struct ListNode* head){
    struct ListNode* slow_ptr = head;
    struct ListNode* fast_ptr = head;
    while(fast_ptr){
        fast_ptr = fast_ptr->next ? fast_ptr->next->next : NULL;
        slow_ptr = slow_ptr->next;
        if(fast_ptr == slow_ptr){
            break;
        }
    }
    if(!fast_ptr){
        return NULL;
    }
    slow_ptr = head;
    while(fast_ptr != slow_ptr){
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    return fast_ptr;
}