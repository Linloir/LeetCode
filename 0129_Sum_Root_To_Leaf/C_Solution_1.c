//C Solution (1) to Leetcode.129
#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

int sumNumbers(struct TreeNode* root){
    int curSum = 0;
    int curNum = 0;
    if(!root){
        return 0;
    }
    sum(root, &curNum, &curSum);
    return curSum;
}

void sum(struct TreeNode* root, int* curNum, int* curAns){
    (*curNum) *= 10;
    (*curNum) += root->val;
    if(!root->left && !root->right){
        (*curAns) += (*curNum);
        return;
    }
    if(root->left){
        sum(root->left, curNum, curAns);
        (*curNum) /= 10;
    }
    if(root->right){
        sum(root->right, curNum, curAns);
        (*curNum) /= 10;
    }
}