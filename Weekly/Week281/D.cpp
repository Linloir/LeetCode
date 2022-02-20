/*** 
 * Author       : Linloir
 * Date         : 2022-02-20 10:29:24
 * LastEditTime : 2022-02-20 13:16:47
 * Description  : 
 */

//Failed

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef long long LL;

LL coutPairs(int* nums, int numsSize, int k){
    int base[100001] = {0};
    for(int i = 0; i < numsSize; i++){
        int curBase = 1;
        int j = 2;
        while(j <= k){
            if(k % j == 0 && nums[i] % j == 0){
                curBase = j;
            }
            j++;
        }
        base[curBase]++;
    }
    LL res = 0;
    for(int i = 2; i * i <= k; i++){
        if(k % i == 0){
            res += base[i] * base[k / i];
        }
    }
    res += base[k] * (numsSize - base[k]);
    return res;
}
