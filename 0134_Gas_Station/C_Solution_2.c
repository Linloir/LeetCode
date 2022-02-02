//C Solution (2) to Leetcode. 134
#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int* gross = (int*)malloc(sizeof(int) * gasSize);
    int chk = 0;
    for(int i = 0; i < gasSize; i++){
        gross[i] = gas[i] - cost[i];
        chk += gross[i];
    }
    if(chk < 0){
        return -1;
    }
    int curStrt = 0;
    int curSum = 0;
    int curStep = 0;
    int p = 0;
    while(curStep < gasSize){
        if(curSum + gross[p] < 0){
            curStrt = p + 1 == gasSize ? 0 : p + 1;
            curStep = 0;
            curSum = 0;
        }
        else{
            curSum += gross[p];
        }
        p = p + 1 == gasSize ? 0 : p + 1;
        curStep++;
    }
    return curStrt;
}

void TestBench(){
    int n;
    scanf("%d", &n);
    int* gas = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &gas[i]);
    }
    int* cost = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &cost[i]);
    }
    int res = canCompleteCircuit(gas, n, cost, n);
    printf("%d\n", res);
}

int main(){
    TestBench();
    return 0;
}