/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 12:38:30
 * LastEditTime : 2022-02-09 14:23:40
 * Description  : Leetcode 173 | Medium | C Solution 1
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TestBench/common_tree.h"

typedef struct {
    struct TreeNode* cur;
    struct TreeNode** stack;
    int stackSize;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* it = (BSTIterator*)malloc(sizeof(BSTIterator));
    it->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 50);
    memset(it->stack, 0, sizeof(struct TreeNode*) * 50);
    it->stackSize = 0;
    while(root){
        it->stack[it->stackSize++] = root;
        root = root->left;
    }
    it->cur = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    it->cur->left = NULL;
    it->cur->right = NULL;
    it->cur->val = it->stack[it->stackSize - 1]->val - 1;
    return it;
}

int bSTIteratorNext(BSTIterator* obj) {
    if(obj->cur->right){
        struct TreeNode* ptr = obj->cur->right;
        while(ptr->left){
            obj->stack[obj->stackSize++] = ptr;
            ptr = ptr->left;
        }
        obj->cur = ptr;
    }
    else{
        obj->cur = obj->stack[--obj->stackSize];
    }
    return obj->cur->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->cur->right || obj->stackSize;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj->cur);
    free(obj);
}
