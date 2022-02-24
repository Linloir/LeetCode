/*** 
 * Author       : Linloir
 * Date         : 2022-02-24 23:02:55
 * LastEditTime : 2022-02-24 23:31:20
 * Description  : [24/2/2022 daily] | LeetCode 1706 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize){
    int** canReachTop = (int**)malloc(sizeof(int*) * (gridSize + 1));
    for(int i = 0; i < gridSize + 1; i++){
        canReachTop[i] = (int*)malloc(sizeof(int) * gridColSize[0]);
    }
    for(int i = 0; i < gridColSize[0]; i++){
        canReachTop[0][i] = 1;
    }
    for(int r = 1; r < gridColSize; r++){
        for(int c = 0; c < gridColSize[0]; c++){
            if(grid[r - 1][c] == 1){
                if(c == 0){
                    canReachTop[r][c] = -1;
                }
                else{
                    canReachTop[r][c] = grid[r - 1][c - 1] == 1 && canReachTop[r - 1][c - 1] == 1 ? 1 : -1;
                }
            }
            else{
                if(c == gridColSize[0] - 1){
                    canReachTop[r][c] = -1;
                }
                else{
                    canReachTop[r][c] = grid[r - 1][c + 1] == -1 && canReachTop[r - 1][c + 1] == 1 ? 1 : -1;
                }
            }
        }
    }
    *returnSize = gridColSize[0];
    return canReachTop[gridSize];
}
