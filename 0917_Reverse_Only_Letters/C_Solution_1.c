/*** 
 * Author       : Linloir
 * Date         : 2022-02-23 23:26:45
 * LastEditTime : 2022-02-23 23:36:53
 * Description  : [23/2/2022 daily] | LeetCode 917 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(void* a, void* b){
    char tmp = *(char*)a;
    *(char*)a = *(char*)b;
    *(char*)b = tmp;
}

char* reverseOnlyLetters(char* s){
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right){
        if(!isalpha(s[left])){
            left++;
            continue;
        }
        if(!isalpha(s[right])){
            right--;
            continue;
        }
        swap(&s[right--], &s[left++]);
    }
    return s;
}
