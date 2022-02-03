//C Solution (1) to Leetcode.139

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

int Verify(char* s, Tree dic){
    if(s[0] == '\0'){
        return true;
    }
    struct treeNode* ptr = dic->desc;
    int valid = false;
    int i = 0;
    while(ptr != NULL && !valid && s[i] != '\0'){
        while(ptr && ptr->c != s[i]){
            ptr = ptr->sibl;
        }
        if(!ptr){
            break;
        }
        if(ptr->isEnd){
            int t = Verify(&s[i + 1], dic);
            valid |= t;
        }
        i++;
        ptr = ptr->desc;
    }
    return valid;
}

int wordBreak(char* s, char** wordDict, int wordDictSize){
    Tree dic = CreateTree();
    for(int i = 0; i < wordDictSize; i++){
        InsertWord(wordDict[i], dic);
    }
    int len = strlen(s);
    return Verify(s, dic);
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