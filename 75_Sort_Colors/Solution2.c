#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize){
    int redCount = 0;
    int blueCount = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            redCount++;
        }
        else if(nums[i] == 2){
            blueCount++;
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(i < redCount){
            nums[i] = 0;
        }
        else if(i < numsSize - blueCount){
            nums[i] = 1;
        }
        else{
            nums[i] = 2;
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