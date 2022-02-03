#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

struct treeNode {
    char c;
    int isEnd;
    struct treeNode* desc;
    struct treeNode* sibl;
};

typedef struct treeNode* Tree;

Tree CreateTree(){
    struct treeNode* newTree = (struct treeNode*)malloc(sizeof(struct treeNode));
    newTree->c = '\0';
    newTree->desc = NULL;
    newTree->sibl = NULL;
    newTree->isEnd = false;
    return newTree;
}

void InsertWord(char* word, Tree root){
    if(word[0] == '\0'){
        root->isEnd = true;
        return;
    }
    //Find next
    struct treeNode* cur = root->desc;
    while(cur){
        if(cur->c == word[0]){
            break;
        }
        cur = cur->sibl;
    }
    if(!cur){
        struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
        newNode->c = word[0];
        newNode->desc = NULL;
        newNode->sibl = root->desc;
        newNode->isEnd = false;
        root->desc = newNode;
        cur = newNode;
    }
    InsertWord(&word[1], cur);
}

int Verify(char* s, int strtPos, Tree dic, int* mem){
    if(s[strtPos] == '\0'){
        return true;
    }
    if(mem[strtPos] == 1){
        return false;
    }
    struct treeNode* cur = dic;
    for(int i = strtPos; s[i] != '\0'; i++){
        cur = cur->desc;
        while(cur && cur->c != s[i]){
            cur = cur->sibl;
        }
        if(!cur){
            return false;
        }
        if(cur->isEnd){
            int tmpt = Verify(s, i + 1, dic, mem);
            if(!tmpt){
                mem[i + 1] = 1;
            }
            else{
                return true;
            }
        }
    }
    return cur->isEnd;
}

int wordBreak(char* s, char** wordDict, int wordDictSize){
    Tree dic = CreateTree();
    for(int i = 0; i < wordDictSize; i++){
        InsertWord(wordDict[i], dic);
    }
    int mem[301] = {0};
    return Verify(s, 0, dic, mem);
}

//TestBench
void TestBench(){
    int size;
    scanf("%d", &size);
    char s[256];
    scanf("%s", s);
    char** wordDict = (char**)malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){
        wordDict[i] = (char*)malloc(sizeof(char) * 256);
        scanf("%s", wordDict[i]);
    }
    int res = wordBreak(s, wordDict, size);
    printf("%s\n", res ? "True" : "False");
}

int main(){
    TestBench();
    return 0;
}