/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   
Memory: 
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int fast = 0;
    int slow = 0;
    for (; fast < numsSize; fast++){
        if(nums[fast] != val)
            nums[slow++] = nums[fast];
    }
    return slow;
}

/*
After Solution:
解法：快慢指针
解题笔记：这种需要对数组进行原地删除的操作都可以考虑快慢指针的算法，与26题原理相同
*/

int main(){
    int test[10] = {3, 2, 4, 6, 7, 2, 3, 3, 5, 1};
    int len = removeElement(test, 10, 3);
    for (int i = 0; i < len; i++){
        printf("%d ", test[i]);
    }
    return 0;
}