//Optimized solution for solution 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;

    struct ListNode* cur = dummyHead;
    while(cur->next && cur->next->next){
        if(cur->next->val == cur->next->next->val){
            int duplicatedVal = cur->next->val;
            while(cur->next && cur->next->val == duplicatedVal){
                cur->next = cur->next->next;
            }
        }
        else{
            cur = cur->next;
        }
    }

    cur = dummyHead->next;
    free(dummyHead);
    return cur;
}

struct ListNode* GenerateList(){
    int n;
    scanf("%d", &n);
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* ptr = dummyHead;
    for(int i = 0; i < n; i++){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &(newNode->val));
            newNode->next = NULL;
            ptr->next = newNode;
            ptr = ptr->next;
    }
    ptr = dummyHead->next;
    free(dummyHead);
    return ptr;
}

void PrintList(struct ListNode* head){
    struct ListNode* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void TestBench(){
    struct ListNode* head = GenerateList();
    head = deleteDuplicates(head);
    PrintList(head);
}

int main(){
    TestBench();
    return 0;
}