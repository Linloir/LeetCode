/*** 
 * Author       : Linloir
 * Date         : 2022-02-08 13:42:42
 * LastEditTime : 2022-02-08 13:55:56
 * Description  : Leetcode 165 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareVersion(char* version1, char* version2){
    char** subVer_1 = (char**)malloc(sizeof(char*) * 500);
    char** subVer_2 = (char**)malloc(sizeof(char*) * 500);
    int verNum_1 = 0;
    int verNum_2 = 0;
    char* tok = strtok(version1, ".");
    while(tok){
        subVer_1[verNum_1++] = tok;
        tok = strtok(NULL, ".");
    }
    tok = strtok(version2, ".");
    while(tok){
        subVer_2[verNum_2++] = tok;
        tok = strtok(NULL, ".");
    }
    int i = 0;
    for(; i < verNum_1 && i < verNum_2; i++){
        int ver1, ver2;
        sscanf(subVer_1[i], "%d", &ver1);
        sscanf(subVer_2[i], "%d", &ver2);
        if(ver1 < ver2){
            return -1;
        }
        else if(ver1 > ver2){
            return 1;
        }
    }
    while(i < verNum_1){
        int ver;
        sscanf(subVer_1[i], "%d", &ver);
        if(ver){
            return 1;
        }
        i++;
    }
    while(i < verNum_2){
        int ver;
        sscanf(subVer_2[i], "%d", &ver);
        if(ver){
            return -1;
        }
        i++;
    }
    return 0;
}

void TestBench(){
    char ver1[500] = {0};
    char ver2[500] = {0};
    scanf("%s%s", ver1, ver2);
    printf("%d\n", compareVersion(ver1, ver2));
}

int main(){
    TestBench();
    return 0;
}
