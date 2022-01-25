//PASSED

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* nums, int numsSize);
void mergeRec(int* nums, int l, int r, int* temp);

void mergeSort(int* nums, int numsSize){
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    mergeRec(nums, 0, numsSize - 1, temp);
}

void mergeRec(int* nums, int l, int r, int* temp){
    if(r <= l){
        return;
    }
    int mid = (l + r) / 2;
    mergeRec(nums, l, mid, temp);
    mergeRec(nums, mid + 1, r, temp);
    int lPtr = l, rPtr = mid + 1;
    int sorted = 0;
    while(lPtr <= mid && rPtr <= r){
        if(nums[lPtr] <= nums[rPtr]){
            temp[sorted++] = nums[lPtr++];
        }
        else{
            temp[sorted++] = nums[rPtr++];
        }
    }
    while(lPtr <= mid){
        temp[sorted++] = nums[lPtr++];
    }
    while(rPtr <= r){
        temp[sorted++] = nums[rPtr++];
    }
    for(int i = 0; i < sorted; i++){
        nums[l + i] = temp[i];
    }
}

int* findLonely(int* nums, int numsSize, int* returnSize){
    mergeSort(nums, numsSize);
    int* res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        if(i - 1 >= 0 && nums[i] - nums[i - 1] <= 1){
            continue;
        }
        else if(i + 1 < numsSize && nums[i + 1] - nums[i] <= 1){
            continue;
        }
        else{
            res[(*returnSize)++] = nums[i];
        }
    }
    res = (int*)realloc(res, sizeof(int) * (*returnSize));
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    int size;
    int* res = findLonely(nums, n, &size);
    for(int i = 0; i < size; i++){
        printf("%d ", res[i]);
    }
    return 0;
}