/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 10:38:07
 * LastEditTime : 2022-02-07 11:18:14
 * Description  : [7/2/2022 daily] | Leetcode 1405 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* longestDiverseString(int a, int b, int c){
    char elements[3] = {'a', 'b', 'c'};
    int weight[3] = {a, b, c};
    if(weight[0] < weight[1]){
        swap(&weight[0], &weight[1]);
        swap_(&elements[0], &elements[1]);
    }
    if(weight[1] < weight[2]){
        swap(&weight[1], &weight[2]);
        swap_(&elements[1], &elements[2]);
    }
    if(weight[0] < weight[1]){
        swap(&weight[0], &weight[1]);
        swap_(&elements[0], &elements[1]);
    }
    char* res = (char*)malloc(sizeof(char) * (a + b + c + 1));
    memset(res, 0, sizeof(char) * (a + b + c + 1));
    int curLen = 0;
    while(weight[0] || weight[1] || weight[2]){
        for(int i = 0; i < 2 && weight[0]; i++){
            res[curLen++] = elements[0];
            weight[0]--;
        }
        if(!weight[1] && !weight[2]){
            break;
        }
        //Insert third
        if(weight[2] > (weight[0] + 1) / 2 && weight[2] >= 2){
            res[curLen++] = elements[2];
            res[curLen++] = elements[2];
            weight[2] -= 2;
        }
        else if(weight[2] && weight[2] == (weight[0] + 1) / 2){
            res[curLen++] = elements[2];
            weight[2]--;
        }
        else if(!weight[1] && weight[2]){
            res[curLen++] = elements[2];
            weight[2]--;
        }
        //Insert second
        if(weight[1] > (weight[0] + 1) / 2){
            res[curLen++] = elements[1];
            weight[1]--;
        }
        if(weight[1]){
            res[curLen++] = elements[1];
            weight[1]--;
        }
    }
    res[curLen] = '\0';
    return res;
}

//TestBench
void TestBench(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", longestDiverseString(a, b, c));
}

int main(){
    TestBench();
    return 0;
}
