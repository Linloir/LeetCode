#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x){
    if(head == NULL){
        return head;
    }

    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;

    struct ListNode* h = dummyHead;
    struct ListNode* t = dummyHead;
    struct ListNode* cur = head;
    while(cur != NULL){
        if(cur->val < x){
            struct ListNode* temp = cur;
            cur = cur->next;
            temp->next = h->next;
            h->next = temp;
            if(h == t){
                t = t->next;
            }
            h = h->next;
        }
        else{
            struct ListNode* temp = cur;
            cur = cur->next;
            temp->next = t->next;
            t->next = temp;
            t = t->next;
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
    int target;
    scanf("%d", &target);
    head = partition(head, target);
    PrintList(head);
}

int main(){
    TestBench();
    return 0;
}