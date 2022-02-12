/*** 
 * Author       : Linloir
 * Date         : 2022-02-12 16:33:56
 * LastEditTime : 2022-02-12 17:36:20
 * Description  : LeetCode 187 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct trieNode{
    int freq;
    struct trieNode** children;
};

typedef struct trieNode* Trie;

int ID(char c){
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    default:
        return 0;
    }
}

Trie CreateTrie(){
    Trie newTrie = (Trie)malloc(sizeof(struct trieNode));
    newTrie->freq = 0;
    newTrie->children = (Trie*)malloc(sizeof(Trie) * 4);
    memset(newTrie->children, 0, sizeof(Trie) * 4);
    return newTrie;
}

bool FindAddStr(Trie trie, char* str){
    int p = 0;
    Trie cur = trie->children[ID(str[p++])];
    Trie prev = trie;
    while(p < 10 && cur){
        prev = cur;
        cur = cur->children[ID(str[p++])];
    }
    if(p == 10 && cur){
        prev->freq++;
        return prev->freq == 1;
    }
    else if(!cur){
        p--;
        while(p < 10){
            Trie newNode = CreateTrie();
            prev->children[ID(str[p])] = newNode;
            prev = newNode;
            p++;
        }
        return false;
    }
    else{
        return false;
    }
}

char** findRepeatedDnaSequences(char* s, int* returnSize){
    if(strlen(s) < 10){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    char** res = (char**)malloc(sizeof(char*) * (*returnSize));
    Trie dic = CreateTrie();
    for(int i = 0; i <= strlen(s) - 10; i++){
        if(FindAddStr(dic, &s[i])){
            res = (char**)realloc(res, sizeof(char*) * (*returnSize + 1));
            char* newStr = (char*)malloc(sizeof(char) * 11);
            memset(newStr, 0, sizeof(char) * 11);
            strncpy(newStr, &s[i], 10);
            res[(*returnSize)] = newStr;
            (*returnSize)++;
        }
    }
    return res;
}

//TestBench
void TestBench(){
    char s[256] = {0};
    scanf("%s", s);
    int size = 0;
    char** res = findRepeatedDnaSequences(s, &size);
    for(int i = 0; i < size; i++){
        printf("%s\n", res[i]);
    }
}

int main(){
    TestBench();
    return 0;
}
