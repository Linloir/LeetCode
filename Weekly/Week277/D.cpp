#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

//FAILED

// int maximumGood(int** statements, int statementsSize, int* statementsColSize){
//     int* stack = (int*)malloc(sizeof(int) * statementsSize);
//     int stackSize = 0;
//     int curMax = 0;
//     for(int i = 0; i < statementsSize; i++){
//         int* judge = (int*)malloc(sizeof(int) * statementsSize);
//         for(int j = 0; j < statementsSize; j++){
//             judge[j] = 2;
//         }
//         stack[stackSize++] = i;
//         int hasConflict = 0;
//         while(stackSize > 0 && !hasConflict){
//             int curPerson = stack[--stackSize];
//             for(int p = 0; p < statementsSize; p++){
//                 if(statements[curPerson][p] == 2){
//                     continue;
//                 }
//                 if(judge[curPerson] == 1){
//                     //curPerson always tells the truth
//                     if(judge[p] == 2){
//                         //Now person p is defined
//                         judge[p] = statements[curPerson][p];
//                         stack[stackSize++] = p;
//                         continue;
//                     }
//                     else if(judge[p] != statements[curPerson][p]){
//                         //Meet a conflict
//                         hasConflict = 1;
//                         break;
//                     }
//                     else{
//                         continue;
//                     }
//                 }
//                 else{
//                     //curPerson could tell a lie
//                     continue;
//                 }
//             }
//         }
//         if(hasConflict){
//             stackSize = 0;
//             free(judge);
//             continue;
//         }
//         int max2 = 0;
//         for(int p = 0; p < statementsSize; p++){
//             //Judge the rest person
//             if(judge[p] != 2){
//                 continue;
//             }
//             else{
//                 int cur = 1;
//                 int hasConflict = 0;
//                 int* changed = (int*)malloc(sizeof(int) * statementsSize);
//                 int changedSize = 0;
//                 judge[p] = 1;
//                 stack[stackSize++] = p;
//                 while(stackSize > 0 && !hasConflict){
//                     int curp = stack[--stackSize];
//                     for(int n = 0; n < statementsSize; n++){
//                         if(statements[curp][n] == 2){
//                             continue;
//                         }
//                         if(judge[curp] == 1){
//                             if (judge[n] == 2){
//                                 judge[n] = statements[curp][n];
//                                 changed[changedSize++] = n;
//                                 if (statements[curp][n] == 1){
//                                     cur++;
//                                 }
//                                 stack[stackSize++] = n;
//                                 continue;
//                             }
//                             else if (statements[curp][n] != judge[n]){
//                                 hasConflict = 1;
//                                 break;
//                             }
//                         }
//                         else{
//                             continue;
//                         }
//                     }
//                 }
//                 if(hasConflict){
//                     judge[p] = 2;
//                     stackSize = 0;
//                     for(int n = 0; n < changedSize; n++){
//                         judge[changed[n]] = 2;
//                     }
//                     changedSize = 0;
//                     free(changed);
//                     continue;
//                 }
//                 for(int n = 0; n < statementsSize; n++){
//                     if(judge[n] == 2){
//                         cur++;
//                     }
//                 }
//                 max2 = cur > max2 ? cur : max2;
//                 judge[p] = 2;
//                 stackSize = 0;
//                 for(int n = 0; n < changedSize; n++){
//                     judge[changed[n]] = 2;
//                 }
//                 changedSize = 0;
//                 free(changed);
//             }
//         }
//         int count = 0;
//         for(int p = 0; p < statementsSize; p++){
//             if(judge[p] == 1){
//                 count++;
//             }
//         }
//         curMax = count + max2 > curMax ? count + max2 : curMax;
//         stackSize = 0;
//         free(judge);
//     }
//     return curMax;
// }

//PASSED

int maximumGood(int** statements, int statementsSize, int* statementsColSize){
    int person = 0;
    int curMax = 0;
    while(person < pow(2, statementsSize)){
        int cur = 0;
        bool hasConflict = 0;
        for(int i = 0; i < statementsSize && !hasConflict; i++){
            if(person & (1 << i)){
                //If good
                for(int j = 0; j < statementsSize && !hasConflict; j++){
                    if(statements[i][j] == 2){
                        continue;
                    }
                    else if(statements[i][j] != ((person >> j) & 1)){
                        hasConflict = 1;
                    }
                }
            }
        }
        if(!hasConflict){
            for(int i = 0; i < statementsSize; i++){
                if(person & (1 << i)){
                    cur++;
                }
            }
            curMax = cur > curMax ? cur : curMax;
        }
        person++;
    }
    return curMax;
}

int main(){
    int statementsSize;
    scanf("%d", &statementsSize);
    int** statements = (int**)malloc(sizeof(int*) * statementsSize);
    int* statementsColSize = (int*)malloc(sizeof(int) * statementsSize);
    for(int i = 0; i < statementsSize; i++){
        statements[i] = (int*)malloc(sizeof(int) * statementsSize);
        statementsColSize[i] = statementsSize;
        for(int j = 0; j < statementsSize; j++){
            scanf("%d", &statements[i][j]);
        }
    }
    printf("%d", maximumGood(statements, statementsSize, statementsColSize));
    return 0;
}