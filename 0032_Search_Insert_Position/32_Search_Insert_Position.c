/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   4ms
Memory: 6.1Mb
*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    if(numsSize == 0 || target <= nums[0])
        return 0;
    int i;
    for (i = 0; i < numsSize; i++){
        if(nums[i] > target)
            return i;
    }
    return i;
}

/*
After Solution:
做题笔记：  在比对数值的时候，不需要两边夹，因为是排序序列，因此如果是前插模式，那么只要在num[i] >= target的时候输出i就是插入的位置
            其次，一定要注意开头和结尾的特殊情况处理
*/

int main(){
    int test[4] = {1, 3, 5, 6};
    int target = 1;
    int result = searchInsert(test, 4, target);
    printf("%d\n", result);
    return 0;
}