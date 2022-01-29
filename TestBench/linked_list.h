#include <stdio.h>
#include <stdlib.h>

#ifndef _GM_
#define _GM_

enum GenerateMethod {
    From_Input = 1,
    From_Random_Generator = 2
};

#endif

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <time.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode* List;

List GenerateFromInput(){
    //Assume input to be [a,b,c,d,e]
    List head = (List)malloc(sizeof(struct ListNode));
    List ptr = head;
    head->next = NULL;
    while(1){
        char c = getchar();
        if(c == '[' || c == ' ' || c == '\n'){
            continue;
        }
        else if(c == ']'){
            break;
        }
        int _buffer_capacity = 4;
        char* _buffer = (char*)malloc(sizeof(char) * _buffer_capacity);
        int _buffer_size = 0;
        while((c >= '0' && c <= '9') || c == '-'){
            _buffer[_buffer_size++] = c;
            if(_buffer_size == _buffer_capacity){
                _buffer_capacity *= 2;
                _buffer = (char*)realloc(_buffer, sizeof(char) * _buffer_capacity);
            }
            c = getchar();
        }
        _buffer[_buffer_size] = '\0';
        List newNode = (List)malloc(sizeof(struct ListNode));
        sscanf(_buffer, "%d", &newNode->val);
        newNode->next = NULL;
        ptr->next = newNode;
        ptr = newNode;
        free(_buffer);
        if(c == ']'){
            break;
        }
    }
    return head;
}

List RandomGenerator(int maxSize, int maxVal){
    srand(time(NULL));
    int size = rand() % maxSize;
    List head = (List)malloc(sizeof(struct ListNode));
    head->next = NULL;
    for(int i = 0; i < size; i++){
        int val = rand() % maxVal;
        List newNode = (List)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

List GenerateList(enum GenerateMethod method, int maxSize, int maxVal){
    switch (method)
    {
    case From_Input:
        return GenerateFromInput();
    case From_Random_Generator:
        return RandomGenerator(maxSize, maxVal);
    default:
        return NULL;
    }
}

void SortList(List head){
    //Insertion sort is implemented
    List iter = head;
    while(iter->next){
        List _insert = head;
        while(_insert->next->val < iter->next->val){
            _insert = _insert->next;
        }
        if(iter == _insert){
            iter = iter->next;
            continue;
        }
        List _temp = iter->next;
        iter->next = iter->next->next;
        _temp->next = _insert->next;
        _insert->next = _temp;
    }
}

void PrintList(List head){
    printf("[");
    List iter = head->next;
    while(iter && iter->next){
        printf("%d,", iter->val);
        iter = iter->next;
    }
    if(iter){
        printf("%d", iter->val);
    }
    printf("]\n");
}

#endif