//TimeOut

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    int size;
    char* word;
    struct Element* parent;
};

typedef struct Element* Set;

Set* CreateUnions(char** words, int wordsSize){
    Set* map = (Set*)malloc(sizeof(Set) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        Set newSet = (Set)malloc(sizeof(struct Element));
        newSet->parent = NULL;
        newSet->word = words[i];
        newSet->size = 1;
        map[i] = newSet;
    }
    return map;
}

Set Find(struct Element* ele){
    struct Element* set = ele;
    while(set->parent){
        set = set->parent;
    }
    return set;
}

void Union(Set a, Set b){
    b->parent = a;
}

int canUnion(char* a, char* b){
    if(abs((int)strlen(a) - (int)strlen(b)) > 1){
        return 0;
    }
    int hasOneDif = 0;
    for(int i = 0; i < strlen(a); i++){
        if(strchr(b, a[i]) == NULL){
            if(hasOneDif){
                return 0;
            }
            else{
                hasOneDif = 1;
            }
        }
    }
    if(hasOneDif && strlen(a) < strlen(b)){
        return 0;
    }
    return 1;
}

int* groupStrings(char** words, int wordsSize, int* returnSize){
    Set* map = CreateUnions(words, wordsSize);
    int* sizeMap = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        sizeMap[i] = 1;
    }
    int size = wordsSize;
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; j < wordsSize; j++){
            if(j == i){
                continue;
            }
            Set A = Find(map[i]);
            Set B = Find(map[j]);
            if(A != B && canUnion(map[i]->word, map[j]->word)){
                Union(A, B);
                size--;
                A->size += B->size;
            }
        }
    }
    int curMax = 1;
    for(int i = 0; i < wordsSize; i++){
        if(map[i]->size > curMax){
            curMax = map[i]->size;
        }
    }
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = size;
    res[1] = curMax;
    *returnSize = 2;
    return res;
}