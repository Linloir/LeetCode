/*** 
 * Author       : Linloir
 * Date         : 2022-02-21 08:08:12
 * LastEditTime : 2022-02-21 09:14:37
 * Description  : [21/2/2022 daily] | LeetCode 838 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pushDominoes(char* dominoes){
    char lastPushed = 'L';
    int lastPushedPos = -1;
    int len = strlen(dominoes);
    for(int i = 0; i < len; i++){
        while(i < len && dominoes[i] == '.'){
            i++;
        }
        if(lastPushed == 'L'){
            if(i < len && dominoes[i] == 'L'){
                for(int j = lastPushedPos + 1; j < i; j++){
                    dominoes[j] = 'L';
                }
                lastPushed = 'L';
                lastPushedPos = i;
            }
            else{
                lastPushed = 'R';
                lastPushedPos = i;
            }
        }
        else{
            if(i < len && dominoes[i] == 'L'){
                int fallLen = (i - lastPushedPos - 1) / 2;
                for(int j = 0; j < fallLen; j++){
                    dominoes[lastPushedPos + 1 + j] = 'R';
                    dominoes[i - 1 - j] = 'L';
                }
                lastPushed = 'L';
                lastPushedPos = i;
            }
            else{
                for(int j = lastPushedPos; j < i; j++){
                    dominoes[j] = 'R';
                }
                lastPushed = 'R';
                lastPushedPos = i;
            }
        }
    }
    return dominoes;
}