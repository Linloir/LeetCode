//Optimized Solution of solution 1
//Avoid using realloc!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsPalindrome(char* s, int strt, int len){
    int i = strt, j = strt + len - 1;
    while(i < j){
        if(s[i++] != s[j--]){
            return 0;
        }
    }
    return 1;
}

void recursion(char* s, int pos, char*** ans, int* ansSize, int* ansColSize, char*** curAns, int* curAnsSize, int sepLen[][17]){
    if(s[pos] == '\0'){
        //Answer
        char** curAnsCpy = (char**)malloc(sizeof(char*) * (*curAnsSize));
        for(int i = 0; i < *curAnsSize; i++){
            curAnsCpy[i] = (*curAns)[i];
        }
        ans[(*ansSize)] = curAnsCpy;
        ansColSize[(*ansSize)] = *curAnsSize;
        (*ansSize)++;
        return;

    }
    for(int i = 0; i < sepLen[pos][0]; i++){
        //Seperate as length i
        char* sep = (char*)malloc(sizeof(char) * (sepLen[pos][i + 1] + 1));
        memset(sep, 0, sizeof(char) * (sepLen[pos][i + 1] + 1));
        strncpy(sep, &s[pos], sepLen[pos][i + 1]);
        *curAns = (char**)realloc(*curAns, sizeof(char*) * (*curAnsSize + 1));
        (*curAns)[(*curAnsSize)++] = sep;
        recursion(s, pos + sepLen[pos][i + 1], ans, ansSize, ansColSize, curAns, curAnsSize, sepLen);
        (*curAnsSize)--;
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes){
    int sepLen[16][17] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        for(int j = 1; i + j <= len; j++){
            if(IsPalindrome(s, i, j)){
                sepLen[i][++sepLen[i][0]] = j;
            }
        }
    }
    int maxSize = 1 << (len - 1);
    *returnSize = 0;
    char*** ans = (char***)malloc(sizeof(char**) * maxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);
    int curAnsSize = 0;
    char** curAns = (char**)malloc(sizeof(char*) * curAnsSize);
    recursion(s, 0, ans, returnSize, *returnColumnSizes, &curAns, &curAnsSize, sepLen);
    return ans;
}

//TestBench
void TestBench(){
    char input[256];
    scanf("%s", input);
    char*** ans;
    int ansSize;
    int* ansColSize;
    ans = partition(input, &ansSize, &ansColSize);
    printf("[");
    for(int i = 0; i < ansSize; i++){
        printf("[");
        for(int j = 0; j < ansColSize[i]; j++){
            printf(" \"%s\" ", ans[i][j]);
        }
        printf("]");
    }
    printf("]");
}

int main(){
    TestBench();
    return 0;
}