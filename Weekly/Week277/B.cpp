//PASSED

#include <stdio.h>
#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize){
    int* pos = (int*)malloc(sizeof(int) * (numsSize / 2));
    int* neg = (int*)malloc(sizeof(int) * (numsSize / 2));
    int posNum = 0, negNum = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] >= 0){
            pos[posNum++] = nums[i];
        }
        else{
            neg[negNum++] = nums[i];
        }
    }
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int i = 0, posPtr = 0, negPtr = 0;
    while(i < numsSize){
        res[i++] = pos[posPtr++];
        res[i++] = neg[negPtr++];
    }
    free(pos);
    free(neg);
    *returnSize = numsSize;
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    int size;
    int* res = rearrangeArray(nums, n, &size);
    for(int i = 0; i < size; i++){
        printf("%d ", res[i]);
    }
    return 0;
}