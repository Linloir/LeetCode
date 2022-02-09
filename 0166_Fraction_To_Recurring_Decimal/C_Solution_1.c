/*** 
 * Author       : Linloir
 * Date         : 2022-02-09 15:32:03
 * LastEditTime : 2022-02-09 16:26:05
 * Description  : Leetcode 166 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct hashNode{
    int key;
    int val;
    struct hashNode* next;
};

struct hashMap{
    struct hashNode** list;
    int mapSize;
};

typedef struct hashMap* Map;

Map CreateMap(int size){
    Map newMap = (Map)malloc(sizeof(struct hashMap));
    newMap->mapSize = size;
    newMap->list = (struct hashNode**)malloc(sizeof(struct hashNode*) * newMap->mapSize);
    memset(newMap->list, 0, sizeof(struct hashNode*) * newMap->mapSize);
    return newMap;
}

struct hashNode* IrstItem(Map map, int key, int val){
    int addr = abs(key) % map->mapSize;
    struct hashNode* dummyHead = (struct hashNode*)malloc(sizeof(struct hashNode));
    dummyHead->next = map->list[addr];
    struct hashNode* ptr = dummyHead;
    while(ptr->next){
        if(ptr->next->key == key){
            return ptr->next;
        }
        ptr = ptr->next;
    }
    struct hashNode* newNode = (struct hashNode*)malloc(sizeof(struct hashNode));
    newNode->val = val;
    newNode->key = key;
    ptr->next = newNode;
    newNode->next = NULL;
    map->list[addr] = dummyHead->next;
    free(dummyHead);
    return newNode;
}

struct hashNode* SrchItem(Map map, int key){
    int addr = abs(key) % map->mapSize;
    struct hashNode* ptr = map->list[addr];
    while(ptr){
        if(ptr->key == key){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

char* fractionToDecimal(int numerator, int denominator){
    bool isNeg = (numerator ^ denominator) < 0;
    long long numer = numerator < 0 ? -(long long)numerator : numerator;
    long long denom = denominator < 0 ? -(long long)denominator : denominator;
    long long integalPart = numer / denom;
    numer -= integalPart * denom;
    int decimalPart[10000] = {0};
    int decimalLength = 0;
    int loopStrt = -1;
    Map remainder = CreateMap(1000);
    while(numer != 0){
        struct hashNode* inserted = IrstItem(remainder, numer, decimalLength);
        if(inserted->val != decimalLength){
            //Loop occurred
            loopStrt = inserted->val;
            break;
        }
        else{
            numer *= 10;
            decimalPart[decimalLength] = numer / denom;
            numer -= decimalPart[decimalLength++] * denom;
        }
    }
    char* res = (char*)malloc(sizeof(char) * 10000);
    memset(res, 0, sizeof(char) * 10000);
    sprintf(res, "%s%lld", isNeg ? integalPart == 0 ? decimalLength ? "-" : "" : "-" : "", integalPart);
    if(decimalLength){
        strcat(res, ".");
    }
    char temp[3] = {0};
    int i = 0;
    if(loopStrt != -1){
        while(i < loopStrt){
            sprintf(temp, "%d", decimalPart[i]);
            strcat(res, temp);
            i++;
        }
        strcat(res, "(");
    }
    while(i < decimalLength){
        sprintf(temp, "%d", decimalPart[i]);
        strcat(res, temp);
        i++;
    }
    if(loopStrt != -1){
        strcat(res, ")");
    }
    return res;
}

//TestBench
void TestBench(){
    int n, d;
    scanf("%d%d", &n, &d);
    printf("%s\n", fractionToDecimal(n, d));
}

int main(){
    TestBench();
    return 0;
}
