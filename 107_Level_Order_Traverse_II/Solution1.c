#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

//Solution1 : Reverse afterwards

struct queue {
    struct TreeNode** dat;
    int size;
    int front;
    int rear;
};

typedef struct queue* Queue;

Queue CreateQueue(){
    Queue newQueue = (Queue)malloc(sizeof(struct queue));
    newQueue->size = 128;
    newQueue->dat = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * newQueue->size);
    newQueue->front = 0;
    newQueue->rear = 0;
    return newQueue;
}

struct TreeNode* Front(Queue queue){
    if(queue->front == queue->rear){
        return NULL;
    }
    return queue->dat[queue->front];
}

struct TreeNode* Back(Queue queue){
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

void PushBack(Queue queue, struct TreeNode* newNode){
    queue->dat[queue->rear] = newNode;
    queue->rear = queue->rear + 1 == queue->size ? 0 : queue->rear + 1;
    if(queue->rear == queue->front){
        //Full
        queue->dat = (struct TreeNode**)realloc(queue->dat, sizeof(struct TreeNode*) * queue->size * 2);
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

void swap(int** a, int** b){
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void swap_(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    if(!root){
        return NULL;
    }
    Queue queue = CreateQueue();
    PushBack(queue, root);
    while(QueueSize(queue) > 0){
        int size = QueueSize(queue);
        int* level = (int*)malloc(sizeof(int) * size);
        for(int i = 0; i < size; i++){
            struct TreeNode* curNode = Front(queue);
            PopFront(queue);
            if(curNode->left){
                PushBack(queue, curNode->left);
            }
            if(curNode->right){
                PushBack(queue, curNode->right);
            }
            level[i] = curNode->val;
        }
        res = (int**)realloc(res, sizeof(int*) * (*returnSize + 1));
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        res[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
    }
    //swap
    int i = 0, j = *returnSize - 1;
    while(i < j){
        swap(&res[i], &res[j]);
        swap_(&(*returnColumnSizes)[i], &(*returnColumnSizes)[j]);
        i++;
        j--;
    }
    return res;
}

//TestBench
void TestBench(){
    Tree testTree = GenerateTree();
    int resSize = 0;
    int* resColSize = NULL;
    int** res = levelOrderBottom(testTree, &resSize, &resColSize);
    PrintTraverseResult(res, resSize, resColSize);
}

int main(){
    TestBench();
    return 0;
}