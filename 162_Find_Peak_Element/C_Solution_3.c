/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 15:10:42
 * LastEditTime : 2022-02-07 15:10:42
 * Description  : Leetcode 162 | Medium | C Solution 3 | O(LogN)
 */

#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize){
    int l = 0, r = numsSize - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[mid] < nums[mid + 1]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}
