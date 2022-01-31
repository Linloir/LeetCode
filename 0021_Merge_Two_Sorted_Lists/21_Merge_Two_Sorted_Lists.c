/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   8ms
Memory: 6.3Mb
*/

#include <stdio.h>

/*Given structure start*/
struct ListNode {
    int val;
    struct ListNode *next;
};
/*Given structure end*/

/*Solution start*/
typedef struct ListNode node;
typedef struct ListNode *PtrToNode;
typedef struct ListNode *List;

List list_create(void);
void list_insert(PtrToNode, int);

List list_create(void){
    List new_list = (List)malloc(sizeof(node));
    new_list->next = NULL;
    new_list->val = NULL;
    return new_list;
}

void list_insert(PtrToNode p, int value){
    PtrToNode new_node = (PtrToNode)malloc(sizeof(node));
    new_node->next = p->next;
    new_node->val = value;
    p->next = new_node;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    List result = list_create();
    PtrToNode iterator_1 = l1;
    PtrToNode iterator_2 = l2;
    PtrToNode iterator = result;
    while(iterator_1->next != NULL){
        if(iterator_2->next != NULL && iterator_1->next->val > iterator_2->next->val){
            do{
                list_insert(iterator, iterator_2->next->val);
                iterator_2 = iterator_2->next;
                iterator = iterator->next;
            } while (iterator_1->next->val > iterator_2->next->val);
            continue;
        }
        list_insert(iterator, iterator_1->next->val);
        iterator_1 = iterator_1->next;
        iterator = iterator->next;
    }
    while (iterator_2->next != NULL){
        list_insert(iterator, iterator_2->next->val);
        iterator_2 = iterator_2->next;
        iterator = iterator->next;
    }
    return result;
}
/*Solution end*/

/*
Better solution
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

Author：demigodliu
Link：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/di-gui-he-bing-liang-ge-you-xu-lian-biao-hghk/
Source：LeetCode
*/

int main(){
    //Test case
    List test_1 = list_create();
    List test_2 = list_create();
    list_insert(test_1, 4);
    list_insert(test_1, 2);
    list_insert(test_1, 1);
    // list_insert(test_1, 2);
    // list_insert(test_1, 2);
    list_insert(test_2, 4);
    list_insert(test_2, 3);
    list_insert(test_2, 1);
    // list_insert(test_2, 7);
    // list_insert(test_2, 3);
    // list_insert(test_2, 2);
    // list_insert(test_2, 1);
    List result = list_create();
    result = mergeTwoLists(test_1, test_2);
    while(result->next != NULL){
        printf("%d\n", result->next->val);
        result = result->next;
    }
    return 0;
}