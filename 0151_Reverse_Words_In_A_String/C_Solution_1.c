/*** 
 * Author       : Linloir
 * Date         : 2022-02-05 12:14:49
 * LastEditTime : 2022-02-05 12:29:20
 * Description  : C Solution 1 to Leetcode 151
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s){
    int len = strlen(s) + 1;
    int stackCpac = 128;
    char** stack = (char**)malloc(sizeof(char*) * stackCpac);
    int stackSize = 0;
    char* tok = strtok(s, " ");
    while(tok){
        stack[stackSize++] = tok;
        if(stackSize == stackCpac){
            stackCpac <<= 1;
            stack = (char**)realloc(stack, sizeof(char*) * stackCpac);
        }
        tok = strtok(NULL, " ");
    }
    char* res = (char*)malloc(sizeof(char) * len);
    memset(res, 0, sizeof(char) * len);
    while(stackSize > 1){
        strcat(res, stack[--stackSize]);
        strcat(res, " ");
    }
    strcat(res, stack[--stackSize]);
    return res;
}

//TestBench
void TestBench(){
    char test[256] = {0};
    gets(test);
    char* res = reverseWords(test);
    printf("%s\n", res);
}

int main(){
    TestBench();
    return 0;
}