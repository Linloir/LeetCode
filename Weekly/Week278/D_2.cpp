//Timeout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    int size;
    unsigned int binaryAlphMap;
    struct Element* parent;
};

typedef struct Element* Set;

Set* CreateUnions(char** words, int wordsSize){
    Set* map = (Set*)malloc(sizeof(Set) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        Set newSet = (Set)malloc(sizeof(struct Element));
        newSet->parent = NULL;
        newSet->size = 1;
        newSet->binaryAlphMap = 0;
        int l = strlen(words[i]);
        for(int j = 0; j < l; j++){
            newSet->binaryAlphMap |= (1 << (words[i][j] - 'a'));
        }
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

int canUnion(int mapA, int mapB){
    unsigned int dif = mapA ^ mapB;
    if(dif == 0){
        return 1;
    }
    while((dif & 1) == 0){
        dif >>= 1;
    }
    dif >>= 1;
    if(dif == 0){
        return 1;
    }
    return 0;
}

int* groupStrings(char** words, int wordsSize, int* returnSize){
    Set* map = CreateUnions(words, wordsSize);
    int curMax = 1;
    int size = wordsSize;
    for(int i = 0; i < wordsSize; i++){
        for(int j = i + 1; j < wordsSize; j++){
            Set A = Find(map[i]);
            Set B = Find(map[j]);
            if(A != B && canUnion(map[i]->binaryAlphMap, map[j]->binaryAlphMap)){
                Union(A, B);
                size--;
                A->size += B->size;
                if(A->size > curMax){
                    curMax = A->size;
                }
            }
        }
    }
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = size;
    res[1] = curMax;
    *returnSize = 2;
    return res;
}