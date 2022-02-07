/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 12:47:01
 * LastEditTime : 2022-02-07 12:58:03
 * Description  : Leetcode 153 | Medium | Optimized solution of solution 2
 */

#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize){
    int l = 0, r = numsSize - 1;
    while(l != r){
        int mid = (l + r) / 2;
        if(nums[mid] < nums[r]){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return nums[l];
}

void TestBench(){
    int size;
    scanf("%d", &size);
    int* nums = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        scanf("%d", &nums[i]);
    }
    printf("%d\n", findMin(nums, size));
}

int main(){
    TestBench();
    return 0;
}

