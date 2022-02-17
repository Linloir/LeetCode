/*** 
 * Author       : Linloir
 * Date         : 2022-02-17 20:45:55
 * LastEditTime : 2022-02-17 21:27:04
 * Description  : [17/2/2022 daily] | LeetCode 688 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int directions[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

double knightProbability(int n, int k, int row, int column){
    double dp[101][26][26];
    memset(dp, 0, sizeof(dp));
    for(int step = 0; step <= k; step++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(step == 0){
                    dp[step][r][c] = 1.0;
                }
                else{
                    int curR = r;
                    int curC = c;
                    for(int d = 0; d < 8; d++){
                        curR = r + directions[d][0];
                        curC = c + directions[d][1];
                        if(curR >= 0 && curR < n && curC >= 0 && curC < n){
                            dp[step][r][c] += dp[step - 1][curR][curC] / 8;
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column];
}