/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 14:26:04
 * LastEditTime : 2022-02-09 15:12:03
 * Description  : Leetcode 179 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isGreater(const int a, const int b){
    char a_b[20] = {0};
    char b_a[20] = {0};
    sprintf(a_b, "%d%d", a, b);
    sprintf(b_a, "%d%d", b, a);
    long long int a_b_num, b_a_num;
    sscanf(a_b, "%lld", &a_b_num);
    sscanf(b_a, "%lld", &b_a_num);
    return a_b_num > b_a_num;
}

void MergeSort(int* nums, int* tempArr, int l, int r){
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    MergeSort(nums, tempArr, l, mid);
    MergeSort(nums, tempArr, mid + 1, r);
    int l_ptr = l;
    int r_ptr = mid + 1;
    int copied = 0;
    while(l_ptr <= mid && r_ptr <= r){
        if(isGreater(nums[l_ptr], nums[r_ptr])){
            tempArr[copied++] = nums[l_ptr++];
        }
        else{
            tempArr[copied++] = nums[r_ptr++];
        }
    }
    while(l_ptr <= mid){
        tempArr[copied++] = nums[l_ptr++];
    }
    while(r_ptr <= r){
        tempArr[copied++] = nums[r_ptr++];
    }
    for(int i = 0; i < copied; i++){
        nums[l + i] = tempArr[i];
    }
}

char* largestNumber(int* nums, int numsSize){
    int* tempArr = (int*)malloc(sizeof(int) * numsSize);
    MergeSort(nums, tempArr, 0, numsSize - 1);
    if(nums[0] == 0){
        char res[2] = {0};
        res[0] = '0';
        return res;
    }
    char* res = (char*)malloc(sizeof(char) * 1000);
    memset(res, 0, sizeof(char) * 1000);
    char temp[10] = {0};
    for(int i = 0; i < numsSize; i++){
        sprintf(temp, "%d", nums[i]);
        strcat(res, temp);
    }
    return res;
}

//TestBench
void TestBench(){
    int numsSize;
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        scanf("%d", &nums[i]);
    }
    printf("%s\n", largestNumber(nums, numsSize));
}

int main(){
    TestBench();
    return 0;
}
