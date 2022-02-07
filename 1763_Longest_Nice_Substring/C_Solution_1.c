/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 10:22:16
 * LastEditTime : 2022-02-07 10:36:51
 * Description  : [1/2/2022 daily] | Leetcode 1763 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longestNiceSubstring(char* s){
    int len = strlen(s);
    int curMax = 0;
    int curStrt = 0;
    for(int i = 0; i < len; i++){
        int lower = 0;
        int upper = 0;
        for(int j = i; j < len; j++){
            if(s[j] >= 'a'){
                lower |= (1 << (s[j] - 'a'));
            }
            else{
                upper |= (1 << (s[j] - 'A'));
            }
            if((lower ^ upper) == 0){
                if(j - i + 1 > curMax){
                    curMax = j - i + 1;
                    curStrt = i;
                }
            }
        }
    }
    char* res = (char*)malloc(sizeof(char) * (curMax + 1));
    memset(res, 0, sizeof(char) * (curMax + 1));
    strncat(res, &s[curStrt], curMax);
    return res;
}
