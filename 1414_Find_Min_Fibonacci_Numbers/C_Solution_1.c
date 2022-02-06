/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 09:54:53
 * LastEditTime : 2022-02-06 10:17:28
 * Description  : [3/2/2022 daily] | Leetcode 1414 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int findMinFibonacciNumbers(int k){
    //Generate Fibonaccis
    int generateSize = 128;
    int* generateNum = (int*)malloc(sizeof(int) * generateSize);
    generateNum[0] = 1;
    generateNum[1] = 1;
    int generated = 2;
    while(generateNum[generated - 1] < k){
        generateNum[generated++] = generateNum[generated - 1] + generateNum[generated - 2];
        if(generated == generateSize){
            generateSize *= 2;
            generateNum = (int*)realloc(generateNum, sizeof(int) * generateSize);
        }
    }
    int i = generated - 1;
    int num = 0;
    while(k){
        if(generateNum[i] > k){
            i--;
            continue;
        }
        k -= generateNum[i];
        num++;
    }
    return num;
}