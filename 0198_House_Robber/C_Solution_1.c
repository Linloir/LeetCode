/*** 
 * Author       : Linloir
 * Date         : 2022-02-12 20:15:29
 * LastEditTime : 2022-02-12 21:24:32
 * Description  : LeetCode 198 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    int t1 = nums[0];
    int t2 = max(t1, nums[1]);
    int n = 2;
    while(n < numsSize){
        int cur = max(nums[n] + t1, t2);
        t1 = t2;
        t2 = cur;
        n++;
    }
    return max(t1, t2);
}
