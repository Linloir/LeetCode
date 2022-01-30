#include <stdio.h>
#include <stdlib.h>

int findFinalValue(int* nums, int numsSize, int original){
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == original){
            return findFinalValue(nums, numsSize, original * 2);
        }
    }
    return original;
}