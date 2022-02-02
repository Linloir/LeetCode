//C Solution (1) to Leetcode.134
//TimeOut

#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int* gross = (int*)malloc(sizeof(int) * gasSize);
    for(int i = 0; i < gasSize; i++){
        gross[i] = gas[i] - cost[i];
    }
    for(int i = 0; i < gasSize; i++){
        if(gross[i] < 0){
            continue;
        }
        int p = i;
        int cur = 0;
        int canComplete = 1;
        do{
            cur += gross[p];
            if(cur < 0){
                canComplete = 0;
            }
            p = p + 1 == gasSize ? 0 : p + 1;
        } while(p != i && canComplete);
        if(canComplete){
            return i;
        }
    }
    return -1;
}