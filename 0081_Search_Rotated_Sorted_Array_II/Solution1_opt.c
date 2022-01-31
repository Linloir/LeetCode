//Optimized version of solution 1
#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return 1;
        }
        //Optimized here
        if(nums[left] == nums[mid] && nums[right] == nums[mid]){
            left++;
            right--;
        }
        else if(nums[mid] <= nums[right]){
            //Right-sorted
            if(target > nums[mid] && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            //Left-sorted
            if(target < nums[mid] && target >= nums[left]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
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