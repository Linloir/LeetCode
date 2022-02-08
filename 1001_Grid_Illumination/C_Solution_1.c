/*** 
 * Author       : Linloir
 * Date         : 2022-02-08 10:30:58
 * LastEditTime : 2022-02-08 11:52:36
 * Description  : [8/2/2022 daily] | Leetcode 1001 | Hard | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pair{
    int row;
    int col;
};

bool isEqual(const struct pair a, const struct pair b){
    return a.row == b.row && a.col == b.col;
}

struct mapNode{
    int key;
    struct pair cord;
    struct mapNode* next;
};

struct hashMap{
    struct mapNode** list;
    int mapSize;
};

typedef struct hashMap* Map;

Map CreateMap(int datSize){
    Map newMap = (Map)malloc(sizeof(struct hashMap));
    newMap->mapSize = 10000;
    newMap->list = (struct MapNode**)malloc(sizeof(struct MapNode*) * newMap->mapSize);
    memset(newMap->list, 0, sizeof(struct MapNode*) * newMap->mapSize);
    return newMap;
}

void IsrtItem(Map map, int key, struct pair cord){
    int addr = abs(key) % map->mapSize;
    struct mapNode* dummyHead = (struct mapNode*)malloc(sizeof(struct mapNode));
    dummyHead->next = map->list[addr];
    struct mapNode* ptr = dummyHead;
    while(ptr->next){
        if(ptr->next->key == key && isEqual(ptr->next->cord, cord)){
            break;
        }
        ptr = ptr->next;
    }
    if(!ptr->next){
        struct mapNode* newNode = (struct mapNode*)malloc(sizeof(struct mapNode));
        newNode->key = key;
        newNode->cord = cord;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    map->list[addr] = dummyHead->next;
    free(dummyHead);
}

bool SrchKey(Map map, int key){
    int addr = abs(key) % map->mapSize;
    struct mapNode* ptr = map->list[addr];
    while(ptr){
        if(ptr->key == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

void DelItem(Map map, int key, struct pair cord){
    int addr = abs(key) % map->mapSize;
    struct mapNode* dummyHead = (struct mapNode*)malloc(sizeof(struct mapNode));
    dummyHead->next = map->list[addr];
    struct mapNode* ptr = dummyHead;
    while(ptr->next){
        if(ptr->next->key == key && isEqual(ptr->next->cord, cord)){
            struct mapNode* found = ptr->next;
            ptr->next = ptr->next->next;
            free(found);
            break;
        }
        ptr = ptr->next;
    }
    map->list[addr] = dummyHead->next;
}

int* gridIllumination(int n, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    //Initial maps
    Map rowMap = CreateMap(n);
    Map colMap = CreateMap(n);
    Map diagMap = CreateMap(n);
    Map antiDiagMap = CreateMap(n);
    //Light lamps
    for(int i = 0; i < lampsSize; i++){
        struct pair curCord;
        curCord.row = lamps[i][0];
        curCord.col = lamps[i][1];
        IsrtItem(rowMap, curCord.row, curCord);
        IsrtItem(colMap, curCord.col, curCord);
        IsrtItem(diagMap, curCord.row + curCord.col, curCord);
        IsrtItem(antiDiagMap, curCord.col - curCord.row, curCord);
    }
    //Execute inqueries
    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    for(int i = 0; i < queriesSize; i++){
        struct pair curCord;
        curCord.row = queries[i][0];
        curCord.col = queries[i][1];
        bool isOn = SrchKey(rowMap, curCord.row) || SrchKey(colMap, curCord.col) || SrchKey(diagMap, curCord.row + curCord.col) || SrchKey(antiDiagMap, curCord.col - curCord.row);
        if(isOn){
            for(int r = -1; r <= 1; r++){
                for(int c = -1; c <= 1; c++){
                    struct pair cord;
                    cord.row = curCord.row + r;
                    cord.col = curCord.col + c;
                    DelItem(rowMap, cord.row, cord);
                    DelItem(colMap, cord.col, cord);
                    DelItem(diagMap, cord.row + cord.col, cord);
                    DelItem(antiDiagMap, cord.col - cord.row, cord);
                }
            }
        }
        ans[i] = isOn ? 1 : 0;
    }
    *returnSize = queriesSize;
    return ans;
}
