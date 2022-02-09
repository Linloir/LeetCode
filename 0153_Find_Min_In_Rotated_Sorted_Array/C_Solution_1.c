/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 12:16:20
 * LastEditTime : 2022-02-07 12:16:21
 * Description  : Leetcode 153 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize){
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < nums[i - 1]){
            return nums[i];
        }
    }
    return nums[0];
}
