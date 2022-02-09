/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 12:19:34
 * LastEditTime : 2022-02-07 12:45:10
 * Description  : Leetcode 153 | Medium | C Solution 2
 */

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int find(int* nums, int l, int r){
    if(l == r){
        return nums[l];
    }
    int mid = (l + r + 1) / 2;
    if(nums[mid] < nums[l]){
        int leftMin = find(nums, l, mid - 1);
        return min(leftMin, nums[mid]);
    }
    else{
        int rightMin = find(nums, mid, r);
        return min(nums[0], rightMin);
    }
}

int findMin(int* nums, int numsSize){
    return find(nums, 0, numsSize - 1);
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
