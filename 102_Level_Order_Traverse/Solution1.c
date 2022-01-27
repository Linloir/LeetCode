#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

struct queue {
    struct TreeNode** data;
    int maxSize;
    int head;
    int tail;
};

typedef struct queue* Queue;

Queue CreateQueue(){
    Queue newQueue = (Queue)malloc(sizeof(struct queue));
    newQueue->maxSize = 2;
    newQueue->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * newQueue->maxSize);
    newQueue->head = 0;
    newQueue->tail = 0;
    return newQueue;
}

struct TreeNode* Front(Queue queue){
    if(queue->head == queue->tail){
        return NULL;
    }
    return queue->data[queue->head];
}

struct TreeNode* Back(Queue queue){
    if(queue->head == queue->tail){
        return NULL;
    }
    return queue->data[queue->tail - 1 < 0 ? queue->maxSize - 1 : queue->tail - 1];
}

void PopFront(Queue queue){
    if(queue->head == queue->tail){
        return;
    }
    queue->head = queue->head + 1 == queue->maxSize ? 0 : queue->head + 1;
}

void PopBack(Queue queue){
    if(queue->head == queue->tail){
        return;
    }
    queue->tail = queue->tail - 1 < 0 ? queue->maxSize - 1 : queue->tail - 1;
}

void PushBack(Queue queue, struct TreeNode* newNode){
    queue->data[queue->tail] = newNode;
    queue->tail = queue->tail + 1 == queue->maxSize ? 0 : queue->tail + 1;
    if(queue->tail == queue->head){
        queue->data = (struct TreeNode**)realloc(queue->data, sizeof(struct TreeNode*) * queue->maxSize * 2);
        for(int i = 0; i < queue->tail; i++){
            queue->data[queue->maxSize + i] = queue->data[i];
        }
        queue->tail = queue->maxSize + queue->tail;
        queue->maxSize *= 2;
    }
}

int QueueSize(Queue queue){
    return queue->head <= queue->tail ? queue->tail - queue->head : queue->maxSize - queue->head + queue->tail;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    Queue queue = CreateQueue();
    PushBack(queue, root);
    PushBack(queue, NULL);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    while(Front(queue)){
        int levelWidth = 0;
        int* level = (int*)malloc(sizeof(int) * levelWidth);
        while(Front(queue) != NULL){
            struct TreeNode* front = Front(queue);
            PopFront(queue);
            if(front->left){
                PushBack(queue, front->left);
            }
            if(front->right){
                PushBack(queue, front->right);
            }
            level = (int*)realloc(level, sizeof(int) * (levelWidth + 1));
            level[levelWidth++] = front->val;
        }
        PopFront(queue);
        PushBack(queue, NULL);
        res = (int**)realloc(res, sizeof(int*) * (*returnSize + 1));
        *returnColumnSizes = (int*)realloc((*returnColumnSizes), sizeof(int) * (*returnSize + 1));
        res[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelWidth;
        (*returnSize)++;
    }
    return res;
}

//TestBench
void TestBench(){
    Tree testTree = GenerateTree();
    int* returnColSize;
    int returnSize;
    int** res = levelOrder(testTree, &returnSize, &returnColSize);
    printf("[");
    for(int i = 0; i < returnSize - 1; i++){
        printf("[");
        for(int j = 0; j < returnColSize[i] - 1; j++){
            printf("%d,", res[i][j]);
        }
        printf("%d],", res[i][returnColSize[i] - 1]);
    }
    printf("[");
    for(int j = 0; j < returnColSize[returnSize - 1] - 1; j++){
        printf("%d,", res[returnSize - 1][j]);
    }
    printf("%d]],", res[returnSize - 1][returnColSize[returnSize - 1] - 1]);
}

int main(){
    TestBench();
    return 0;
}