#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int traverse(int** grid, int rNum, int cNum, int r, int c, int curRes){
    if(r < 0 || c < 0 || r >= rNum || c >= cNum){
        return curRes;
    }
    if(grid[r][c] == 0){
        return curRes;
    }
    int cur = grid[r][c];
    curRes += cur;
    grid[r][c] = 0;
    int left = traverse(grid, rNum, cNum, r, c - 1, curRes);
    int up = traverse(grid, rNum, cNum, r - 1, c, curRes);
    int right = traverse(grid, rNum, cNum, r, c + 1, curRes);
    int down = traverse(grid, rNum, cNum, r + 1, c, curRes);
    grid[r][c] = cur;
    int max = max(max(left, right), max(up, down));
    return max;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize){
    int rNum = gridSize;
    int cNum = gridColSize[0];
    int curNum = 0;
    for(int i = 0; i < rNum; i++){
        for(int j = 0; j < cNum; j++){
            int cur = traverse(grid, rNum, cNum, i, j, 0);
            curNum = max(cur, curNum);
        }
    }
    return curNum;
}