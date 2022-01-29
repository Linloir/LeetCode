#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#ifndef _COMMON_TREE_
#define _COMMON_TREE_

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode* Tree;

char* ReadInput(){
    int _max_input_length = 256;
    char* input = (char*)malloc(sizeof(char) * _max_input_length);
    int input_length = 0;
    while(1){
        char c = getchar();
        if(c == '[')    continue;
        else if(c == ']')   break;
        else{
            input[input_length++] = c;
            if(input_length == _max_input_length){
                _max_input_length *= 2;
                input = (char*)realloc(input, sizeof(char) * _max_input_length);
            }
        }
    }
    input[input_length] = '\0';
    return input;
}

int* GetInputArray(int* inputSize){
    *inputSize = 0;
    int* input = (int*)malloc(sizeof(int) * (*inputSize));
    while(1){
        char c = getchar();
        if(c == '[' || c == ' ' || c == '\n'){
            continue;
        }
        else{
            char buffer[64] = {0};
            int i = 0;
            while(c != ',' && c != ']'){
                buffer[i++] = c;
                c = getchar();
            }
            input = (int*)realloc(input, sizeof(int) * (*inputSize + 1));
            sscanf(buffer, "%d", &input[(*inputSize)++]);
            
        }
        if(c == ']'){
            break;
        }
    }
    return input;
}

Tree GenerateTree(){
    //Read Input
    char* commonInput = ReadInput();
    //Parse Input
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int head = 0;
    int tail = 0;
    char* subStr = strtok(commonInput, ",");
    if(subStr == NULL || strcmp(subStr, "null") == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    sscanf(subStr, "%d", &root->val);
    queue[tail++] = root;
    while(tail - head > 0){
        struct TreeNode* curRoot = queue[head++];
        struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->left = NULL;
        left->right = NULL;
        subStr = strtok(NULL, ",");
        if(!subStr){
            break;
        }
        else if(strcmp(subStr, "null") != 0){
            sscanf(subStr, "%d", &left->val);
            curRoot->left = left;
            queue[tail++] = left;
        }
        struct TreeNode* right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        right->left = NULL;
        right->right = NULL;
        subStr = strtok(NULL, ",");
        if(!subStr){
            break;
        }
        else if(strcmp(subStr, "null") != 0){
            sscanf(subStr, "%d", &right->val);
            curRoot->right = right;
            queue[tail++] = right;
        }
    }
    return root;
}

void InorderPrint(Tree root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        printf(" %d ", root->val);
        return;
    }
    if(root->left){
        InorderPrint(root->left);
    }
    else{
        printf(" null ");
    }
    printf(" %d ", root->val);
    if(root->right){
        InorderPrint(root->right);
    }
    else{
        printf(" null ");
    }
}

void PrintTree(Tree root){
    printf("[");
    InorderPrint(root);
    printf("]\n");
}

void PrintTraverseResult(int** res, int resSize, int* resColSize){
    printf("[");
    for(int i = 0; i < resSize - 1; i++){
        printf("[");
        for(int j = 0; j < resColSize[i] - 1; j++){
            printf("%d,", res[i][j]);
        }
        printf("%d],", res[i][resColSize[i] - 1]);
    }
    printf("[");
    for(int j = 0; resSize > 0 && j < resColSize[resSize - 1] - 1; j++){
        printf("%d,", res[resSize - 1][j]);
    }
    if(resSize > 0)
        printf("%d]]", res[resSize - 1][resColSize[resSize - 1] - 1]);
    else
        printf("]]");
}

#endif