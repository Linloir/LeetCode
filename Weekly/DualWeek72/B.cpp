/*** 
 * Author       : Linloir
 * Date         : 2022-02-19 22:40:36
 * LastEditTime : 2022-02-20 00:11:47
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>

long long* sumOfThree(long long num, int* returnSize){
    if(num / 3 != (double)num / 3){
        *returnSize = 0;
        return NULL;
    }
    else{
        long long* res = (long long*)malloc(sizeof(long long) * 3);
        long long center = num / 3;
        res[0] = center - 1;
        res[1] = center;
        res[2] = center + 1;
        *returnSize = 3;
        return res;
    }
}
