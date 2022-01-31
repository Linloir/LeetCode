#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct queue {
    struct Node** dat;
    int size;
    int front;
    int rear;
};

typedef struct queue* Queue;

Queue createQueue(){
    Queue newQueue = (Queue)malloc(sizeof(struct queue));
    newQueue->size = 100;
    newQueue->dat = (struct Node**)malloc(sizeof(struct Node*) * newQueue->size);
    newQueue->front = 0;
    newQueue->rear = 0;
    return newQueue;
}

struct Node* Front(Queue queue){
    if(queue->front == queue->rear){
        return NULL;
    }
    return queue->dat[queue->front];
}

void PopFront(Queue queue){
    if(queue->front == queue->rear){
        return;
    }
    queue->front = queue->front + 1 == queue->size ? 0 : queue->front + 1;
}

void PushBack(Queue queue, struct Node* node){
    queue->dat[queue->rear] = node;
    queue->rear = queue->rear + 1 == queue->size ? 0 : queue->rear + 1;
    if(queue->rear == queue->front){
        //Full
        queue->dat = (struct Node**)realloc(queue->dat, sizeof(struct Node*) * queue->size * 2);
        for(int i = 0; i < queue->rear; i++){
            queue->dat[queue->size + i] = queue->dat[i];
        }
        queue->rear += queue->size;
        queue->size *= 2;
    }
}

int QueueSize(Queue queue){
    return queue->rear >= queue->front ? queue->rear - queue->front : queue->size - queue->front + queue->rear;
}

struct Node* connect(struct Node* root) {
    Queue queue = createQueue();
    PushBack(queue, root);
    struct Node* dummyHead = (struct Node*)malloc(sizeof(struct Node));
    while(QueueSize(queue) > 0){
        int size = QueueSize(queue);
        dummyHead->next = NULL;
        struct Node* ptr = dummyHead;
        for(int i = 0; i < size; i++){
            ptr->next = Front(queue);
            PopFront(queue);
            ptr = ptr->next;
            if(ptr->left){
                PushBack(queue, ptr->left);
            }
            if(ptr->right){
                PushBack(queue, ptr->right);
            }
        }
        ptr->next = NULL;
    }
    free(dummyHead);
}