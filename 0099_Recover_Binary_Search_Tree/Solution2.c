//Solution 2:Use a stack

#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

void swap(struct TreeNode* a, struct TreeNode* b){
    int tempVal = a->val;
    a->val = b->val;
    b->val = tempVal;
}

void recoverTree(struct TreeNode* root){
    struct TreeNode** Stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 256);
    int stackSize = 0;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    struct TreeNode* pred = NULL;
    Stack[stackSize++] = root;
    while(Stack[stackSize - 1]->left){
        Stack[stackSize] = Stack[stackSize - 1]->left;
        stackSize++;
    }
    while(stackSize > 0){
        struct TreeNode* curNode = Stack[--stackSize];
        if(pred && pred->val > curNode->val){
            if(first == NULL){
                first = pred;
            }
            second = curNode;
        }
        pred = curNode;
        if(curNode->right){
            Stack[stackSize++] = curNode->right;
            while(Stack[stackSize - 1]->left){
                Stack[stackSize] = Stack[stackSize - 1]->left;
                stackSize++;
            }
        }
    }
    swap(first, second);
}

//Tree Testbench
void TestBench(){
    Tree testTree = GenerateTree();
    PrintTree(testTree);
    recoverTree(testTree);
    PrintTree(testTree);
}

int main(){
    TestBench();
    return 0;
}