/*** 
 * Author       : Linloir
 * Date         : 2022-02-15 22:31:35
 * LastEditTime : 2022-02-15 23:27:44
 * Description  : [15/2/2022 daily] | LeetCode 1380 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* rowFlag = (int*)malloc(sizeof(int) * matrixSize);
    int* columnFlag = (int*)malloc(sizeof(int) * matrixColSize[0]);
    memset(rowFlag, 0, sizeof(int) * matrixSize);
    memset(columnFlag, 0, sizeof(int) * matrixColSize[0]);
    for(int i = 0; i < matrixSize; i++){
        int min = 0;
        for(int j = 0; j < matrixColSize[i]; j++){
            columnFlag[j] = matrix[i][j] > matrix[columnFlag[j]][j] ? i : columnFlag[j];
            min = matrix[i][j] < matrix[i][min] ? j : min;
        }
        rowFlag[i] = min;
    }
    int* ans = (int*)malloc(sizeof(int) * matrixSize);
    *returnSize = 0;
    for(int i = 0; i < matrixSize; i++){
        if(columnFlag[rowFlag[i]] == i){
            ans[(*returnSize)++] = matrix[i][rowFlag[i]];
        }
    }
    return ans;
}
