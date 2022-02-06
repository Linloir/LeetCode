/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 10:28:24
 * LastEditTime : 2022-02-06 10:38:37
 * Description  : [Weekly 279] | A
 */

#include <stdio.h>
#include <stdlib.h>

int* sortEvenOdd(int* nums, int numsSize, int* returnSize){
    for(int i = 0; i < numsSize; i += 2){
        for(int j = 0; j < numsSize - i - 2; j += 2){
            if(nums[j] > nums[j + 2]){
                int temp = nums[j];
                nums[j] = nums[j + 2];
                nums[j + 2] = temp;
            }
        }
    }
    for(int i = 1; i < numsSize; i += 2){
        for(int j = 1; j < numsSize - i - 1; j += 2){
            if(nums[j] < nums[j + 2]){
                int temp = nums[j];
                nums[j] = nums[j + 2];
                nums[j + 2] = temp;
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}