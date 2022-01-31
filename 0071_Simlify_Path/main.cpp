#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

struct dualQueue{
    int maxSize;
    char** data;
    int head;
    int tail;
};

typedef struct dualQueue* DualQueue;

DualQueue CreateQueue(){
    DualQueue newQueue = (DualQueue)malloc(sizeof(struct dualQueue));
    newQueue->maxSize = 10;
    newQueue->data = (char**)malloc(sizeof(char*) * newQueue->maxSize);
    newQueue->head = 0;
    newQueue->tail = 0;
    return newQueue;
}

void AdjustQueue(DualQueue q, int newSize){
    if(q->head != 0){
        for(int i = 0; i < q->tail - q->head; i++){
            q->data[i] = q->data[q->head + i];
        }
        q->tail -= q->head;
        q->head = 0;
    }
    q->data = (char**)realloc(q->data, sizeof(char*) * newSize);
    q->maxSize = newSize;
}

void Enqueue(DualQueue q, char* str){
    q->data[q->tail++] = str;
    if(q->tail == q->maxSize){
        AdjustQueue(q, q->maxSize * 2);
    }
}

char* Front(DualQueue q){
    if(q->head < q->tail){
        return q->data[q->head];
    }
    else{
        return NULL;
    }
}

char* Back(DualQueue q){
    if(q->tail > q->head){
        return q->data[q->tail - 1];
    }
    else{
        return NULL;
    }
}

void PopFront(DualQueue q){
    if(q->head >= q->tail){
        return;
    }
    q->head++;
    if(q->tail - q->head < q->maxSize / 2){
        AdjustQueue(q, q->maxSize / 2);
    }
}

void PopBack(DualQueue q){
    if(q->tail <= q->head){
        return;
    }
    q->tail--;
    if(q->tail - q->head < q->maxSize / 2){
        AdjustQueue(q, q->maxSize / 2);
    }
}

int QueueSize(DualQueue q){
    return q->tail - q->head;
}

char * simplifyPath(char * path){
    DualQueue queue = CreateQueue();
    int ptr = 0;
    while(1){
        if(path[ptr] == '\0'){
            break;
        }
        //Ignore /
        while(path[ptr] == '/'){
            ptr++;
        }
        //Read path
        char* curPath = (char*)malloc(sizeof(char) * 30);
        int l = 0;
        while(path[ptr] != '/' && path[ptr] != '\0'){
            curPath[l++] = path[ptr++];
        }
        curPath[l] = '\0';
        //Compare path
        if(strcmp(curPath, ".") == 0 || l == 0){
            free(curPath);
            continue;
        }
        else if(strcmp(curPath, "..") == 0){
            free(curPath);
            PopBack(queue);
        }
        else{
            Enqueue(queue, curPath);
        }
    }
    char* res = (char*)malloc(sizeof(char) * (strlen(path) + 1));
    memset(res, 0, sizeof(char) * (strlen(path) + 1));
    int size = QueueSize(queue);
    strcat(res, "/");
    for(int i = 0; i < size - 1; i++){
        strcat(res, Front(queue));
        PopFront(queue);
        strcat(res, "/");
    }
    strcat(res, Front(queue) == NULL ? "" : Front(queue));
    return res;
}

int main(){
    char path[3000];
    scanf("%s", path);
    char* res = simplifyPath(path);
    printf("%s\n", res);
    return 0;
}