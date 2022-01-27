//Solution 1: Construct inorder array
//and find the misordered elements
#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

void swap(struct TreeNode* a, struct TreeNode* b){
    int tempVal = a->val;
    a->val = b->val;
    b->val = tempVal;
}

void inorderTraverse(struct TreeNode* root, struct TreeNode** res, int* resSize){
    if(!root){
        return;
    }
    inorderTraverse(root->left, res, resSize);
    res[(*resSize)++] = root;
    inorderTraverse(root->right, res, resSize);
}

void findAndSwap(struct TreeNode** inorder, int inorderSize){
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    for(int i = 0; i < inorderSize - 1; i++){
        if(inorder[i]->val > inorder[i + 1]->val){
            if(first == NULL){
                first = inorder[i];
                second = inorder[i + 1];
            }
            else{
                second = inorder[i + 1];
            }
        }
    }
    swap(first, second);
}

void recoverTree(struct TreeNode* root){
    int _max_node_count = 1000;
    struct TreeNode** inorder = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * _max_node_count);
    int inorderSize = 0;
    inorderTraverse(root, inorder, &inorderSize);
    findAndSwap(inorder, inorderSize);
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