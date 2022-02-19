/*** 
 * Author       : Linloir
 * Date         : 2022-02-18 20:48:23
 * LastEditTime : 2022-02-18 21:35:44
 * Description  : [18/2/2022 daily] | LeetCode 1791 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

struct mapNode {
    int key;
    int degree;
    struct mapNode* next;
};

struct hashMap{
    struct mapNode** list;
    int mapSize;
};

typedef struct hashMap* Map;

Map CreateMap(int mapSize){
    Map newMap = (Map)malloc(sizeof(struct hashMap));
    newMap->mapSize = mapSize;
    newMap->list = (struct mapNode**)malloc(sizeof(struct mapNode*) * mapSize);
    for(int i = 0; i < mapSize; i++){
        newMap->list[i] = NULL;
    }
    return newMap;
}

struct mapNode* Find(Map map, int key){
    int addr = key % map->mapSize;
    struct mapNode* ptr = map->list[addr];
    while(ptr){
        if(ptr->key == key){
            return ptr;
        }
        else{
            ptr = ptr->next;
        }
    }
    return ptr;
}

void Isrt(Map map, int key){
    int addr = key % map->mapSize;
    struct mapNode* newNode = (struct mapNode*)malloc(sizeof(struct mapNode));
    newNode->key = key;
    newNode->degree = 1;
    newNode->next = map->list[addr];
    map->list[addr] = newNode;
}

int findCenter(int** edges, int edgesSize, int* edgesColSize){
    Map dic = CreateMap(1000);
    for(int i = 0; i < edgesSize; i++){
        if(!Find(dic, edges[i][0])){
            Isrt(dic, edges[i][0]);
        }
        else{
            return edges[i][0];
        }
        if(!Find(dic, edges[i][1])){
            Isrt(dic, edges[i][1]);
        }
        else{
            return edges[i][1];
        }
    }
    return 0;
}
