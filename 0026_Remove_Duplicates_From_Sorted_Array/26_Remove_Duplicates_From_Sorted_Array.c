/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   28ms
Memory: 8.5Mb
*/

int removeDuplicates(int* nums, int numsSize){
    int delta = 0;
    if(numsSize == 0)
        return 0;
    int i = 1;
    for (; i < numsSize - delta; i++){
        while(i < numsSize - delta && nums[i + delta] == nums[i + delta - 1])
            delta++;
        if(i == numsSize - delta){
            break;
        }
        nums[i] = nums[i + delta];
    }
    return i;
}

/*
After the Solution:
考点：快慢指针
解法：指定一个快指针和一个慢指针，快指针按1步进向前查找符合项，每一个符合将慢指针向前步进1，直到快指针越界
*/

int main(){
    int nums[2] = {1, 1};
    int len = removeDuplicates(nums, 2);
    for (int i = 0; i < len; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}