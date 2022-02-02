//C Solution (1) to Leetcode.137
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int singleNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize;){
        int same = 0;
        for(int j = i + 1; j < numsSize && same < 2; j++){
            if(nums[j] == nums[i]){
                same++;
                swap(&nums[i + same], &nums[j]);
            }
        }
        if(same == 0){
            return nums[i];
        }
        i += 3;
    }
    return nums[numsSize - 1];
}

//TestBench
void TestBench(){
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    int res = singleNumber(nums, n);
    printf("%d\n", res);
}

int main(){
    TestBench();
    return 0;
}