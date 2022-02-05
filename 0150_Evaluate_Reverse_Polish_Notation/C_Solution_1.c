/*** 
 * Author       : Linloir
 * Date         : 2022-02-05 11:53:21
 * LastEditTime : 2022-02-05 12:13:23
 * Description  : C Solution 1 to Leetcode 150
 */

#include <stdio.h>
#include <stdlib.h>

int eval(char token, int numA, int numB){
    switch (token)
    {
    case '+':
        return numA + numB;
    case '-':
        return numA - numB;
    case '*':
        return numA * numB;
    case '/':
        return numA / numB;
    default:
        return 0;
    }
}

int evalRPN(char** tokens, int tokensSize){
    int numStackCap = 16;
    int* numStack = (int*)malloc(sizeof(int) * numStackCap);
    int stackSize = 0;
    for(int i = 0; i < tokensSize; i++){
        int num;
        if(sscanf(tokens[i], "%d", &num)){
            numStack[stackSize++] = num;
            if(stackSize == numStackCap){
                numStackCap *= 2;
                numStack = (int*)realloc(numStack, sizeof(int) * numStackCap);
            }
        }
        else{
            int numB = numStack[--stackSize];
            int numA = numStack[--stackSize];
            int ev = eval(tokens[i][0], numA, numB);
            numStack[stackSize++] = ev;
        }
    }
    int res = numStack[0];
    free(numStack);
    return res;
}