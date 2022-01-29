#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

void flatten(struct TreeNode* root){
    struct TreeNode* cur = root;
    struct TreeNode* next;
    while(cur){
        if(cur->left){
            struct TreeNode* it = cur->left;
            while(it->right){
                it = it->right;
            }
            it->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

//TestBench
void TestBench(){
    Tree testTree = GenerateTree();
    flatten(testTree);
    PrintTree(testTree);
}

int main(){
    TestBench();
    return 0;
}