#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"

//Solution 1: Recall

int** ans;
int* ansColSize;
int ansSize;
int maxAnsSize;

int* curAns;
int curAnsSize;
int curMaxSize;

void Recursion(struct TreeNode* root, int targetSum){
    if(root == NULL){
        return;
    }
    curAns[curAnsSize++] = root->val;
    if(curAnsSize == curMaxSize){
        curAns = (int*)realloc(curAns, sizeof(int) * curMaxSize * 2);
        curMaxSize *= 2;
    }
    if(root->left == NULL && root->right == NULL && targetSum == root->val){
        int* newAns = (int*)malloc(sizeof(int) * curAnsSize);
        for(int i = 0; i < curAnsSize; i++){
            newAns[i] = curAns[i];
        }
        ans[ansSize] = newAns;
        ansColSize[ansSize] = curAnsSize;
        ansSize++;
        if(ansSize == maxAnsSize){
            ans = (int**)realloc(ans, sizeof(int*) * maxAnsSize * 2);
            ansColSize = (int*)realloc(ansColSize, sizeof(int) * maxAnsSize * 2);
            maxAnsSize *= 2;
        }
    }
    if(root->left){
        Recursion(root->left, targetSum - root->val);
    }
    if(root->right){
        Recursion(root->right, targetSum - root->val);
    }
    curAnsSize--;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    ansSize = 0;
    maxAnsSize = 100;
    ans = (int**)malloc(sizeof(int*) * maxAnsSize);
    ansColSize = (int*)malloc(sizeof(int) * maxAnsSize);
    curAnsSize = 0;
    curMaxSize = 100;
    curAns = (int*)malloc(sizeof(int) * curMaxSize);
    Recursion(root, targetSum);
    *returnSize = ansSize;
    *returnColumnSizes = ansColSize;
    return ans;
}

//TestBench
void TestBench(){
    Tree testTree = GenerateTree();
    int target;
    scanf("%d", &target);
    int resSize = 0;
    int* resColSize = NULL;
    int** res = pathSum(testTree, target, &resSize, &resColSize);
    PrintTraverseResult(res, resSize, resColSize);
}

int main(){
    TestBench();
    return 0;
}