/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 12:11:12
 * LastEditTime : 2022-02-09 12:21:49
 * Description  : [9/2/2022 daily] | Leetcode 2006 | Easy | C Solution 2
 */

#include <stdio.h>
#include <stdlib.h>

int countKDifference(int* nums, int numsSize, int k){
    int count[101] = {0};
    int res = 0;
    for(int i = numsSize - 1; i >= 0; i--){
        if(k - nums[i] > 0){
            res += count[abs(k - nums[i])];
        }
        if(k + nums[i] <= 100){
            res += count[k + nums[i]];
        }
        count[nums[i]]++;
    }
    return res;
}
