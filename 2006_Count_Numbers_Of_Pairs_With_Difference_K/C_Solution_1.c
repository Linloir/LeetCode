/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 12:08:04
 * LastEditTime : 2022-02-09 14:25:21
 * Description  : [9/2/2022 daily] | Leetcode 2006 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int countKDifference(int* nums, int numsSize, int k){
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(abs(nums[i] - nums[j]) == k){
                count++;
            }
        }
    }
    return count;
}
