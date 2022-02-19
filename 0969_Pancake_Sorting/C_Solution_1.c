/*** 
 * Author       : Linloir
 * Date         : 2022-02-19 21:39:00
 * LastEditTime : 2022-02-19 22:21:48
 * Description  : [19/2/2022 daily] | LeetCode 969 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int right, int* ans, int* ansSize){
    if(right < 1){
        return;
    }
    if(right == 1){
        //Final situation
        if(arr[0] > arr[1]){
            //Unsorted
            ans[(*ansSize)++] = 2;
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return;
    }
    //sort 0 ~ right - 1
    sort(arr, right - 1, ans, ansSize);
    //Find insert position
    int pos = right;
    int cur = arr[right];
    while(pos && arr[pos - 1] > cur){
        arr[pos] = arr[pos - 1];
        pos--;
    }
    arr[pos] = cur;
    if(pos != right){
        if((*ansSize) && right == ans[(*ansSize) - 1]){
            (*ansSize)--;
        }
        else{
            ans[(*ansSize)++] = right;
        }
        ans[(*ansSize)++] = right + 1;
        if(pos)
        ans[(*ansSize)++] = pos + 1;
        if(pos > 1)
            ans[(*ansSize)++] = pos;
    }
}

int* pancakeSort(int* arr, int arrSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * arrSize * 10);
    *returnSize = 0;
    sort(arr, arrSize - 1, res, returnSize);
    return res;
}
