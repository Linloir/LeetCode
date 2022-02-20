/*** 
 * Author       : Linloir
 * Date         : 2022-02-19 22:43:40
 * LastEditTime : 2022-02-20 00:11:46
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long LL;

bool rec(LL curLeftSum, LL curSubber, LL* curRes, int* resSize){
    if(curLeftSum == 0){
        return true;
    }
    while(curLeftSum >= curSubber){
        curRes[(*resSize)++] = curSubber;
        bool curSol = rec(curLeftSum - curSubber, curSubber + 2, curRes, resSize);
        curSubber += 2;
        if(curSol){
            return true;
        }
        else{
            (*resSize)--;
        }
    }
    return false;
}

long long* maximumEvenSplit(long long finalSum, int* returnSize){
    if(finalSum % 2 == 1){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    LL* res = (LL*)malloc(sizeof(LL) * 100000);
    *returnSize = 0;
    rec(finalSum, 2, res, returnSize);
    return res;
}
