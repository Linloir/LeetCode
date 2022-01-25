#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i];
        int j = i;
        while(j > 0 && nums[j - 1] > temp){
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
}

void sortColors(int* nums, int numsSize){
    //try insertion sort
    InsertionSort(nums, numsSize);
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