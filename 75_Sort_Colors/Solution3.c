//Single pointer solution
#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize){
    int sorted = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            nums[i] = nums[sorted];
            nums[sorted++] = 0;
        }
    }
    for(int i = sorted; i < numsSize; i++){
        if(nums[i] == 1){
            nums[i] = nums[sorted];
            nums[sorted++] = 1;
        }
    }
}

int main(){
    int numsSize;
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        scanf("%d", &nums[i]);
    }
    sortColors(nums, numsSize);
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}