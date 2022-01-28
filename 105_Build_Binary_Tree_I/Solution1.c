#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int leftSize = 0;
    while(leftSize < preorderSize && inorder[leftSize] != preorder[0]){
        leftSize++;
    }
    root->left = buildTree(&preorder[1], leftSize, &inorder[0], leftSize);
    int rightSize = preorderSize - 1 - leftSize;
    root->right = buildTree(&preorder[leftSize + 1], rightSize, &inorder[leftSize + 1], rightSize);
    return root;
}

//TestBench
void TestBench(){
    int preorderSize = 0;
    int* preorder = GetInputArray(&preorderSize);
    int inorderSize = 0;
    int* inorder = GetInputArray(&inorderSize);
    Tree res = buildTree(preorder, preorderSize, inorder, inorderSize);
    PrintTree(res);
}

int main(){
    TestBench();
    return 0;
}