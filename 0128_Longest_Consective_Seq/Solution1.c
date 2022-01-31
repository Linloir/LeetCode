//Try Disjoint Set ADT

#include <stdio.h>
#include <stdlib.h>

//Disjoint Set
struct set {
    int key;
    int childrenSize;
    struct set* parent;
};

typedef struct set* Set;

Set Find(Set ele){
    Set ptr = ele;
    while(ptr->parent){
        ptr = ptr->parent;
    }
    return ptr;
}

void Union(Set a, Set b){
    b->parent = a;
}

//Hash Map

struct hash_node {
    Set ele;
    struct hash_node* next;
};

struct hash_map {
    struct hash_node** nodeList;
    int mapSize;
};

typedef struct hash_node* HashNode;
typedef struct hash_map* HashMap;

HashMap CreateMap(int size){
    HashMap newMap = (HashMap)malloc(sizeof(struct hash_map));
    newMap->mapSize = size <= 0 ? 1 : size;
    newMap->nodeList = (HashNode*)malloc(sizeof(HashNode) * newMap->mapSize);
    for(int i = 0; i < newMap->mapSize; i++){
        newMap->nodeList[i] = NULL;
    }
    return newMap;
}

void MapInsert(HashMap map, Set ele){
    int addr = abs(ele->key) % map->mapSize;
    HashNode newNode = (HashNode)malloc(sizeof(struct hash_node));
    newNode->ele = ele;
    newNode->next = map->nodeList[addr];
    map->nodeList[addr] = newNode;
}

HashNode MapFind(HashMap map, int key){
    int addr = abs(key) % map->mapSize;
    HashNode ptr = map->nodeList[addr];
    while(ptr){
        if(ptr->ele->key == key){
            return ptr;
        }
        ptr = ptr->next;
    }
    return ptr;
}

int longestConsecutive(int* nums, int numsSize){
    //Create map
    HashMap numMap = CreateMap(numsSize * 2);
    for(int i = 0; i < numsSize; i++){
        Set newSet = (Set)malloc(sizeof(struct set));
        newSet->key = nums[i];
        newSet->parent = NULL;
        newSet->childrenSize = 1;
        MapInsert(numMap, newSet);
    }
    //Traverse and union
    int curMax = 1;
    for(int i = 0; i < numsSize; i++){
        HashNode cur = MapFind(numMap, nums[i]);
        //find +1
        HashNode add_1 = MapFind(numMap, nums[i] + 1);
        if(add_1){
            Set A = Find(cur->ele);
            Set B = Find(add_1->ele);
            if(A != B){
                Union(A, B);
                A->childrenSize += B->childrenSize;
            }
            //Set curMax;
            if(A->childrenSize > curMax){
                curMax = A->childrenSize;
            }
        }
    }
    return curMax;
}