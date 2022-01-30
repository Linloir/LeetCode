#include <stdio.h>
#include <stdlib.h>

int* maxScoreIndices(int* nums, int numsSize, int* returnSize){
    int* zeroes = (int*)malloc(sizeof(int) * (numsSize + 1));
    int* ones = (int*)malloc(sizeof(int) * (numsSize + 1));
    zeroes[0] = 0;
    ones[numsSize] = 0;
    for(int i = 1; i <= numsSize; i++){
        zeroes[i] = zeroes[i - 1] + (nums[i - 1] == 0 ? 1 : 0);
        ones[numsSize - i] = ones[numsSize - i + 1] + (nums[numsSize - i] == 1 ? 1 : 0);
    }
    int* res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    int curMax = 0;
    for(int i = 0; i <= numsSize; i++){
        int curScore = zeroes[i] + ones[i];
        if(curScore == curMax){
            res[(*returnSize)++] = i;
        }
        else if(curScore > curMax){
            curMax = curScore;
            *returnSize = 0;
            res[(*returnSize)++] = i;
        }
    }
    res = (int*)realloc(res, sizeof(int) * (*returnSize));
    return res;
}