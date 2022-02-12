/*** 
 * Author       : Linloir
 * Date         : 2022-02-10 21:09:08
 * LastEditTime : 2022-02-10 21:22:19
 * Description  : [10/2/2022 daily] | Leetcode 1447 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

char** simplifiedFractions(int n, int* returnSize){
    char** res = (char**)malloc(sizeof(char*) * 1000);
    *returnSize = 0;
    int Flag[101][101] = {0};
    for(int denom = 2; denom <= n; denom++){
        for(int numer = 1; numer < denom; numer++){
            if(!Flag[denom][numer]){
                char* temp = (char*)malloc(sizeof(char) * 8);
                memset(temp, 0, sizeof(char) * 8);
                sprintf(temp, "%d/%d", numer, denom);
                res[(*returnSize)++] = temp;
                int mult_numer = numer;
                int mult_denom = denom;
                while(mult_denom <= n){
                    Flag[mult_denom][mult_numer] = 1;
                    mult_denom += denom;
                    mult_numer += numer;
                }
            }
        }
    }
    return res;
}