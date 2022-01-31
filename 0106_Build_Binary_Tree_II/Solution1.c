#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int leftSize = 0;
    while(leftSize < inorderSize && inorder[leftSize] != postorder[postorderSize - 1]){
        leftSize++;
    }
    root->left = buildTree(inorder, leftSize, postorder, leftSize);
    int rightSize = postorderSize - 1 - leftSize;
    root->right = buildTree(&inorder[leftSize + 1], rightSize, &postorder[leftSize], rightSize);
    return root;
}

//Testbench
void TestBench(){
    int inorderSize = 0;
    int* inorder = GetInputArray(&inorderSize);
    int postorderSize = 0;
    int* postorder = GetInputArray(&postorderSize);
    Tree res = buildTree(inorder, inorderSize, postorder, postorderSize);
    PrintTree(res);
}

int main(){
    TestBench();
    return 0;
}