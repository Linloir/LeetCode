#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"
#include "../TestBench/linked_list.h"

struct TreeNode* flattenTraverse(struct TreeNode* root){
    struct TreeNode* last = root;
    if(root->left){
        struct TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        last = flattenTraverse(root->right);
        last->right = temp;
    }
    return last->right ? flattenTraverse(last->right) : last;
}

void flatten(struct TreeNode* root){
    if(!root){
        return;
    }
    flattenTraverse(root);
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