/*** 
 * Author       : Linloir
 * Date         : 2022-02-12 16:10:38
 * LastEditTime : 2022-02-12 16:20:24
 * Description  : [12/2/2022 daily] | Leetcode 1020 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

void paint(int** grid, int gridSize, int* gridColSize, int r, int c){
    if(r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r]){
        return;
    }
    if(grid[r][c] == -1 || grid[r][c] == 0){
        return;
    }
    grid[r][c] = -1;
    paint(grid, gridSize, gridColSize, r + 1, c);
    paint(grid, gridSize, gridColSize, r, c + 1);
    paint(grid, gridSize, gridColSize, r - 1, c);
    paint(grid, gridSize, gridColSize, r, c - 1);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize){
    for(int c = 0; c < gridColSize[0]; c++){
        paint(grid, gridSize, gridColSize, 0, c);
        paint(grid, gridSize, gridColSize, gridSize - 1, c);
    }
    for(int r = 1; r < gridSize - 1; r++){
        paint(grid, gridSize, gridColSize, r, 0);
        paint(grid, gridSize, gridColSize, r, gridColSize[0] - 1);
    }
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[0]; j++){
            if(count[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}
