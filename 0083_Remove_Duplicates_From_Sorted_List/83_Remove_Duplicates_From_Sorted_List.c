/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   8ms
Memory: 6.2Mb
*/

#include <stdio.h>

/*Definition for singly-linked list*/
struct ListNode {
    int val;
    struct ListNode *next;
};
/*End of definition*/

void list_insert(struct ListNode* head, int val){
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = head->next;
    head->next = new_node;
}

/*Solution start*/
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode* cur = head;
    while (cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}
/*Solution end*/

int main(){
    struct ListNode *new_list = (struct LinstNode *)malloc(sizeof(struct ListNode));
    new_list->next = NULL;
    new_list->val = NULL;
    list_insert(new_list, 1);
    list_insert(new_list, 1);
    list_insert(new_list, 2);
    list_insert(new_list, 4);
    list_insert(new_list, 4);
    list_insert(new_list, 5);
    struct ListNode *result = deleteDuplicates(new_list->next);
    struct ListNode *iterator = result;
    while(iterator != NULL){
        printf("%d ", iterator->val);
        iterator = iterator->next;
    }
    return 0;
}