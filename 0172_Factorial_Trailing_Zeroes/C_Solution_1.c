/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 12:23:05
 * LastEditTime : 2022-02-09 12:37:19
 * Description  : Leetcode 172 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int trailingZeroes(int n){
    int res = 0;
    int cur = 5;
    while(cur <= n){
        res += n / cur;
        cur *= 5;
    }
    return res;
}
