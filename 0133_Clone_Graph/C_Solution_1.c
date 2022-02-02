//C Solution (1) to Leetcode.133
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct queue {
    struct Node** dat;
    int size;
    int front;
    int rear;
};

typedef struct queue* Queue;

Queue CreateQueue(){
    Queue newQueue = (Queue)malloc(sizeof(struct queue));
    newQueue->size = 128;
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

struct Node* Back(Queue queue){
    if(queue->front == queue->rear){
        return NULL;
    }
    return queue->dat[queue->rear == 0 ? queue->size - 1 : queue->rear - 1];
}

void PopFront(Queue queue){
    if(queue->front == queue->rear){
        return;
    }
    queue->front = queue->front + 1 == queue->size ? 0 : queue->front + 1;
}

void PopBack(Queue queue){
    if(queue->front == queue->rear){
        return;
    }
    queue->rear = queue->rear == 0 ? queue->size - 1 : queue->rear - 1;
}

void PushBack(Queue queue, struct Node* newNode){
    queue->dat[queue->rear] = newNode;
    queue->rear = queue->rear + 1 == queue->size ? 0 : queue->rear + 1;
    if(queue->rear == queue->front){
        //Full
        queue->dat = (struct Node**)realloc(queue->dat, sizeof(struct Node*) * queue->size * 2);
        for(int i = 0; i < queue->rear; i++){
            queue->dat[queue->size + i] = queue->dat[i];
        }
        queue->rear = queue->size + queue->rear;
        queue->size *= 2;
    }
}

int QueueSize(Queue queue){
    return queue->rear >= queue->front ? queue->rear - queue->front : queue->size - queue->front + queue->rear;
}

struct Node* cloneGraph(struct Node* s){
    if(!s){
        return NULL;
    }
    struct Node* cloned = (struct Node*)malloc(sizeof(struct Node));
    cloned->val = s->val;
    cloned->numNeighbors = s->numNeighbors;
    cloned->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloned->numNeighbors);
    struct Node* flag[101];
    for(int i = 0; i < 101; i++){
        flag[i] = NULL;
    }
    Queue queue = CreateQueue();
    Queue cpyQueue = CreateQueue();
    PushBack(queue, s);
    PushBack(cpyQueue, cloned);
    while(QueueSize(queue) > 0){
        struct Node* cur = Front(queue);
        struct Node* cpy = Front(cpyQueue);
        PopFront(queue);
        PopFront(cpyQueue);
        flag[cpy->val] = cpy;
        for(int i = 0; i < cur->numNeighbors; i++){
            if(flag[cur->neighbors[i]->val]){
                cpy->neighbors[i] = flag[cur->neighbors[i]->val];
            }
            else{
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->numNeighbors = cur->neighbors[i]->numNeighbors;
                newNode->val = cur->neighbors[i]->val;
                newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * newNode->numNeighbors);
                cpy->neighbors[i] = newNode;
                PushBack(queue, cur->neighbors[i]);
                PushBack(cpyQueue, newNode);
            }
        }
    }
    return cloned;
}