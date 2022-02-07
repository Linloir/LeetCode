/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 11:20:20
 * LastEditTime : 2022-02-07 11:59:31
 * Description  : Leetcode 152 | Medium | S Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int maxProduct(int* nums, int numsSize){
    int curMax = nums[0];
    int curPositive = 0;
    int curNegative = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < 0){
            //if is the second negative number
            if(curNegative < 0){
                int temp = curPositive * nums[i];
                curPositive = curNegative * nums[i];
                curNegative = temp < nums[i] ? temp : nums[i];
                if(curPositive > curMax){
                    curMax = curPositive;
                }
            }
            else{
                curNegative = curPositive * nums[i];
                if(nums[i] < curNegative){
                    curNegative = nums[i];
                }
                curPositive = 0;
                if(curNegative > curMax){
                    curMax = curPositive;
                }
            }
        }
        else{
            curNegative *= nums[i];
            curPositive *= nums[i];
            if(nums[i] > curPositive){
                curPositive = nums[i];
            }
            if(curPositive > curMax){
                curMax = curPositive;
            }
        }
    }
    return curMax;
}

void TestBench(){
    int size;
    scanf("%d", &size);
    int* nums = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        scanf("%d", &nums[i]);
    }
    printf("%d\n", maxProduct(nums, size));
}

int main(){
    TestBench();
    return 0;
}
