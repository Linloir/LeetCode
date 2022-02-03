#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

struct ListNode* detectCycle(struct ListNode* head){
    int slow_steps = 0;
    struct ListNode* slow_ptr = head;
    int fast_steps = 0;
    struct ListNode* fast_ptr = head;
    while(fast_ptr){
        fast_ptr = fast_ptr->next ? fast_ptr->next->next : NULL;
        slow_ptr = slow_ptr->next;
        fast_steps += 2;
        slow_steps += 1;
        if(fast_ptr == slow_ptr){
            break;
        }
    }
    if(!fast_ptr){
        return NULL;
    }
    int round = fast_steps - slow_steps;
    fast_ptr = head;
    for(int i = 0; i < round; i++){
        fast_ptr = fast_ptr->next;
    }
    slow_ptr = head;
    while(fast_ptr != slow_ptr){
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    return fast_ptr;
}