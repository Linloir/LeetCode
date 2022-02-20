/*** 
 * Author       : Linloir
 * Date         : 2022-02-20 10:29:18
 * LastEditTime : 2022-02-20 10:48:36
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* newptr = dummyHead;
    struct ListNode* origptr = head;
    while(origptr){
        if(origptr->val == 0){
            int sum = 0;
            struct ListNode* traverseptr = origptr->next;
            if(!traverseptr){
                break;
            }
            while(traverseptr->val != 0){
                sum += traverseptr->val;
                traverseptr = traverseptr->next;
            }
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = sum;
            newNode->next = NULL;
            newptr->next = newNode;
            newptr = newNode;
            origptr = traverseptr;
        }
    }
    return dummyHead->next;
}