#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* ptr = dummyHead;
    struct ListNode* next = dummyHead->next;
    int isDuplicated = 0;
    while(next != NULL && next->next != NULL){
        if(next->val == next->next->val){
            isDuplicated = 1;
            next = next->next;
        }
        else if(isDuplicated){
            next = next->next;
            isDuplicated = 0;
        }
        else{
            ptr->next = next;
            ptr = ptr->next;
            next = ptr->next;
            isDuplicated = 0;
        }
    }
    if(next != NULL && isDuplicated == 0){
        ptr->next = next;
    }
    else{
        ptr->next = NULL;
    }
    struct ListNode* ans = dummyHead->next;
    free(dummyHead);
    return ans;
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