/*** 
 * Author       : Linloir
 * Date         : 2022-02-20 10:29:21
 * LastEditTime : 2022-02-20 10:59:09
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeatLimitedString(char* s, int repeatLimit){
    int count[27] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        count[s[i] - 'a']++;
    }
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int resSize = 0;
    for(int i = 25; i >= 0; i--){
        while(count[i]){
            if(count[i] > repeatLimit){
                count[i] -= repeatLimit;
                for(int k = 0; k < repeatLimit; k++){
                    res[resSize++] = 'a' + i;
                }
                int j = i - 1;
                for(; j >= 0; j--){
                    if(count[j]){
                        count[j]--;
                        res[resSize++] = 'a' + j;
                        break;
                    }
                }
                if(j < 0){
                    break;
                }
            }
            else{
                for(int k = 0; k < count[i]; k++){
                    res[resSize++] = 'a' + i;
                }
                count[i] = 0;
            }
        }
    }
    res[resSize] = '\0';
    return res;
}
