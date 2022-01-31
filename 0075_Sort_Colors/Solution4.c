//Dual pointer solution A
//Set pointers for sorted 0 and 1
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize){
    int ptr_0 = 0;
    int ptr_1 = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            swap(&nums[ptr_1++], &nums[i]);
        }
        else if(nums[i] == 0){
            swap(&nums[ptr_0], &nums[i]);
            if(ptr_0 < ptr_1){
                swap(&nums[ptr_1], &nums[i]);
            }
            ptr_0++;
            ptr_1++;
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