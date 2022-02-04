#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/linked_list.h"

struct dualqueue {
    struct ListNode** dat;
    int size;
    int front;
    int rear;
};

typedef struct dualqueue* DualQueue;

DualQueue CreateQueue(){
    DualQueue newQueue = (DualQueue)malloc(sizeof(struct dualqueue));
    newQueue->size = 100;
    newQueue->dat = (struct ListNode**)malloc(sizeof(struct ListNode*) * newQueue->size);
    newQueue->front = 0;
    newQueue->rear = 0;
    return newQueue;
}

struct ListNode* Front(DualQueue queue){
    if(queue->front == queue->rear){
        return NULL;
    }
    return queue->dat[queue->front];
}

struct ListNode* Back(DualQueue queue){
    if(queue->front == queue->rear){
        return NULL;
    }
    return queue->dat[queue->rear == 0 ? queue->size - 1 : queue->rear - 1];
}

void PopFront(DualQueue queue){
    if(queue->front == queue->rear){
        return;
    }
    queue->front = queue->front + 1 == queue->size ? 0 : queue->front + 1;
}

void PopBack(DualQueue queue){
    if(queue->front == queue->rear){
        return;
    }
    queue->rear = queue->rear == 0 ? queue->size - 1 : queue->rear - 1;
}

void PushBack(DualQueue queue, struct ListNode* newNode){
    queue->dat[queue->rear] = newNode;
    queue->rear = queue->rear + 1 == queue->size ? 0 : queue->rear + 1;
    if(queue->rear == queue->front){
        queue->dat = (struct ListNode**)realloc(queue->dat, sizeof(struct ListNode*) * queue->size * 2);
        queue->rear += queue->size;
        queue->size *= 2;
    }
}

int QueueSize(DualQueue queue){
    return queue->rear >= queue->front ? queue->rear - queue->front : queue->size - queue->front + queue->rear;
}

void reorderList(struct ListNode* head){
    DualQueue queue = CreateQueue();
    struct ListNode* ptr = head;
    while(ptr){
        struct ListNode* newNode = ptr;
        ptr = ptr->next;
        newNode->next = NULL;
        PushBack(queue, newNode);
    }
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    ptr = dummyHead;
    while(QueueSize(queue) > 0){
        struct ListNode* front = Front(queue);
        PopFront(queue);
        struct ListNode* back = Back(queue);
        PopBack(queue);
        if(front){
            ptr->next = front;
            ptr = ptr->next;
        }
        if(back){
            ptr->next = back;
            ptr = ptr->next;
        }
    }
    return dummyHead->next;
}