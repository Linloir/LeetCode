/*** 
 * Author       : Linloir
 * Date         : 2022-02-05 11:18:12
 * LastEditTime : 2022-02-05 11:52:41
 * Description  : C Solution 1 to Leetcode 148
 * Note         : Using merge sort
 */

#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

struct ListNode* mergeSortList(struct ListNode* head){
    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    //Find center
    struct ListNode* fst = head;
    struct ListNode* slw = head;
    while(fst->next){
        fst = fst->next;
        if(fst->next){
            fst = fst->next;
            slw = slw->next;
        }
    }
    fst = slw->next;
    slw->next = NULL;
    struct ListNode* list_1;
    struct ListNode* list_2;
    list_1 = mergeSortList(head);
    list_2 = mergeSortList(fst);
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* ptr = dummyHead;
    while(list_1 && list_2){
        if(list_1->val < list_2->val){
            ptr->next = list_1;
            list_1 = list_1->next;
        }
        else{
            ptr->next = list_2;
            list_2 = list_2->next;
        }
        ptr = ptr->next;
        ptr->next = NULL;
    }
    while(list_1){
        ptr->next = list_1;
        list_1 = list_1->next;
        ptr = ptr->next;
        ptr->next = NULL;
    }
    while(list_2){
        ptr->next = list_2;
        list_2 = list_2->next;
        ptr = ptr->next;
        ptr->next = NULL;
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}

struct ListNode* sortList(struct ListNode* head){
    head->next = mergeSortList(head->next);
    return head;
}

//TestBench
void TestBench(){
    int cases = 5;
    srand(time(NULL));
    while(cases--){
        List testList = GenerateList(From_Random_Generator, 20, 20);
        PrintList(testList);
        testList = sortList(testList);
        PrintList(testList);
    }
}

int main(){
    TestBench();
    return 0;
}