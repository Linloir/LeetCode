//Passed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    int size;
    struct Element* parent;
};

typedef struct Element* Set;

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

int getKey(char* word){
    int key = 0;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        key |= (1 << (word[i] - 'a'));
    }
    return key;
}

struct MapNode {
    int key;
    struct Element* ele;
    struct MapNode* next;
};

struct Map {
    struct MapNode* head;
    int mapSize;
    int curSize;
};

typedef struct Map* HashMap;

HashMap CreateMap(int size){
    HashMap unorderedMap = (HashMap)malloc(sizeof(struct Map));
    unorderedMap->mapSize = size ? size : 1;
    unorderedMap->head = (struct MapNode*)malloc(sizeof(struct MapNode) * unorderedMap->mapSize);
    for(int i = 0; i < unorderedMap->mapSize; i++){
        unorderedMap->head[i].next = NULL;
    }
    unorderedMap->curSize = 0;
    return unorderedMap;
}

struct MapNode* FindWord(HashMap map, int key){
    int addr = key % map->mapSize;
    struct MapNode* ptr = map->head[addr].next;
    while(ptr){
        if(ptr->key == key){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void InsertWord(HashMap map, int key){
    int addr = key % map->mapSize;
    struct MapNode* target = FindWord(map, key);
    if(target){
        target->ele->size++;
        return;
    }
    else{
        struct MapNode* newNode = (struct MapNode*)malloc(sizeof(struct MapNode));
        newNode->key = key;
        newNode->ele = (struct Element*)malloc(sizeof(struct Element));
        newNode->ele->parent = NULL;
        newNode->ele->size = 1;
        newNode->next = map->head[addr].next;
        map->head[addr].next = newNode;
        map->curSize++;
    }
}

struct MapNode* GetMapItem(HashMap map){
    static struct MapNode* item = NULL;
    static int addr = 0;
    static int count = 0;
    if(!item){
        while(map->head[addr].next == NULL){
            addr++;
        }
        item = map->head[addr].next;
    }
    struct MapNode* ret = item;
    item = item->next;
    if(!item){
        addr++;
        while(addr < map->mapSize && map->head[addr].next == NULL){
            addr++;
        }
        if(addr < map->mapSize)
            item = map->head[addr].next;
        else{
            addr = 0;
            item = NULL;
        }
    }
    count++;
    return ret;
}

int* groupStrings(char** words, int wordsSize, int* returnSize){
    HashMap wordMap = CreateMap(wordsSize);
    for(int i = 0; i < wordsSize; i++){
        InsertWord(wordMap, getKey(words[i]));
    }
    int curMax = 1;
    int size = wordMap->curSize;
    //printf("%d", wordMap->curSize);
    for(int i = 0; i < wordMap->curSize; i++){
        struct MapNode* curWord = GetMapItem(wordMap);
        int curSize = Find(curWord->ele)->size;
        if(curSize > curMax){
            curMax = curSize;
        }
        for(int j = 0; j < 26; j++){
            if (curWord->key & (1 << j)){
                int pairedKey = curWord->key - (1 << j);
                struct MapNode* paired = FindWord(wordMap, pairedKey);
                if(paired){
                    Set a = Find(curWord->ele);
                    Set b = Find(paired->ele);
                    if (a != b){
                        Union(a, b);
                        --size;
                        a->size += b->size;
                        if (a->size > curMax){
                            curMax = a->size;
                        }
                    }
                }
                for(int k = 0; k < 26; k++){
                    if(k != j && ((pairedKey & (1 << k)) == 0)){
                        int _pairedKey = pairedKey + (1 << k);
                        paired = FindWord(wordMap, _pairedKey);
                        if(paired){
                            Set a = Find(curWord->ele);
                            Set b = Find(paired->ele);
                            if(a != b){
                                Union(a, b);
                                --size;
                                a->size += b->size;
                                if(a->size > curMax){
                                    curMax = a->size;
                                }
                            }
                        }
                    }
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