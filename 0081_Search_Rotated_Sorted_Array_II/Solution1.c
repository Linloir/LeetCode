#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return 1;
        }
        //Judge if right-sorted
        if(nums[mid] <= nums[right] && nums[mid] < nums[left]){
            if(nums[mid] < target && nums[right] >= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else if(nums[mid] > nums[right]){
            if(nums[mid] > target && nums[left] <= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            for(int i = left; i <= right; i++){
                if(nums[i] == target){
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}

void testBench(){
    int numsSize;
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        scanf("%d", &nums[i]);
    }
    int target;
    scanf("%d", &target);
    int res = search(nums, numsSize, target);
    printf("%s\n", res ? "True" : "False");
}

int main(){
    testBench();
    return 0;
}