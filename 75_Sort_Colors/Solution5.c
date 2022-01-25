//Dual pointer solution B
//Set pointers for sorted 0 and 2
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize){
    int ptr_0 = 0;
    int ptr_2 = numsSize - 1;
    int i = 0;
    while(i <= ptr_2){
        while(i <= ptr_2 && nums[i] == 2){
            swap(&nums[i], &nums[ptr_2--]);
        }
        if(nums[i] == 0){
            swap(&nums[i], &nums[ptr_0++]);
        }
        i++;
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