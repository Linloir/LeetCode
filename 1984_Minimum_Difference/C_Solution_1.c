/*** 
 * Author       : Linloir
 * Date         : 2022-02-11 20:52:07
 * LastEditTime : 2022-02-11 21:13:40
 * Description  : [11/2/2022 daily] | Leetcode 1984 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* nums, int* tempArr, int left, int right){
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(nums, tempArr, left, mid);
    mergeSort(nums, tempArr, mid + 1, right);
    int left_ptr = left;
    int right_ptr = mid + 1;
    int copied = 0;
    while(left_ptr <= mid && right_ptr <= right){
        if(nums[left_ptr] < nums[right_ptr]){
            tempArr[copied++] = nums[left_ptr];
            left_ptr++;
        }
        else{
            tempArr[copied++] = nums[right_ptr];
            right_ptr++;
        }
    }
    while(left_ptr <= mid){
        tempArr[copied++] = nums[left_ptr];
        left_ptr++;
    }
    while(right_ptr <= right){
        tempArr[copied++] = nums[right_ptr];
        right_ptr++;
    }
    for(int i = 0; i < copied; i++){
        nums[left + i] = tempArr[i];
    }
}

int minimumDifference(int* nums, int numsSize, int k){
    int* tempArr = (int*)malloc(sizeof(int) * numsSize);
    mergeSort(nums, tempArr, 0, numsSize - 1);
    int minDif = 2147483647;
    for(int i = 0; i < numsSize - k + 1; i++){
        int dif = nums[i + k - 1] - nums[i];
        minDif = dif < minDif ? dif : minDif;
    }
    return minDif;
}

void TestBench(){
    int size;
    scanf("%d", &size);
    int* nums = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        scanf("%d", &nums[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%d\n", minimumDifference(nums, size, k));
}

int main(){
    TestBench();
    return 0;
}
