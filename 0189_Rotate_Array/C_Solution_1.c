/*** 
 * Author       : Linloir
 * Date         : 2022-02-12 17:55:51
 * LastEditTime : 2022-02-12 18:03:42
 * Description  : LeetCode 189 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory>

void rotate(int* nums, int numsSize, int k){
    if(k % numsSize == 0){
        return;
    }
    k = k % numsSize;
    int* temp = (int*)malloc(sizeof(int) * k);
    memcpy(temp, &nums[numsSize - k], sizeof(int) * k);
    memmove(&nums[k], nums, sizeof(int) * (numsSize - k));
    memcpy(nums, temp, sizeof(int) * k);
}
