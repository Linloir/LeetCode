/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   516ms
Memory: 6.2Mb
*/

#include <stdio.h>

//Solution 1: Division method
int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int divide = numsSize / 2;
    int max_left = maxSubArray(nums, divide);
    int max_right = maxSubArray(nums + divide, numsSize - divide);
    int max_center = -__INT_MAX__;
    /*
    After Solution:
    解题笔记：  下面我自己的算法可以再进行优化，将求中间的最大值也分为左右两部分:
                左边从divide-1开始步进递减，寻找大于divide-1地址的子序和最大值max_c_l(默认为nums[divide-1])；
                右边同理，从divide开始步进递增，寻找大于divide地址的子序和最大值max_c_r(默认为nums[divide])；
                将max_c_l与max_c_r相加得到max_c；
    */
    for (int i = divide - 1; i >= 0; i--){
        int tmp = 0;
        for (int j = i; j < divide; j++)
            tmp += nums[j];
        for (int j = divide; j < numsSize; j++)
        {
            tmp += nums[j];
            if (tmp > max_center)
                max_center = tmp;
        }
    }
    /*
    Better way:
    int max_c_l = nums[divide - 1];
    int max_c_r = nums[divide];
    int tmp;
    int iterator;
    tmp = max_c_l;
    iterator = divide - 1;
    while(--iterator >= 0){
        tmp += nums[iterator];
        if(tmp > max_c_l)
            max_c_l = tmp;
    }
    tmp = max_c_r;
    iterator = divide;
    while(++iterator < numsSize){
        tmp += nums[iterator];
        if(tmp > max_c_r)
            max_c_r = tmp;
    }
    max_center = max_c_l + max_c_r;
    */
    int max = max_left > max_right ? max_left : max_right;
    max = max > max_center ? max : max_center;
    return max;
}

int main(){
    int test[5] = {5,4,-1,7,8};
    int result = maxSubArray(test, 5);
    printf("%d\n", result);
    return 0;
}