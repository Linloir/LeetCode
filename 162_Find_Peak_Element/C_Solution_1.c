/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 14:35:29
 * LastEditTime : 2022-02-07 14:38:44
 * Description  : Leetcode 162 | Medium | C Solution 1 | O(N)
 */

#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i++){
        if((i == 0 || nums[i] > nums[i - 1]) && nums[i] > nums[i + 1]){
            return i;
        }
    }
    return numsSize - 1;
}
