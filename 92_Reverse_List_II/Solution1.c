#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(!head){
        return head;
    }

    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;

    struct ListNode* cur = dummyHead;
    struct ListNode* tail = dummyHead->next;
    int nextPos = 1;

    while(tail){
        if(nextPos == left){
            struct ListNode* next = tail->next;
            nextPos++;
            while(next && nextPos <= right){
                tail->next = next->next;
                next->next = cur->next;
                cur->next = next;
                next = tail->next;
                nextPos++;
            }
            cur = tail;
            tail = tail->next;
        }
        else{
            cur = cur->next;
            tail = tail->next;
            nextPos++;
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
    int left, right;
    scanf("%d%d", &left, &right);
    head = reverseBetween(head, left, right);
    PrintList(head);
}

int main(){
    TestBench();
    return 0;
}