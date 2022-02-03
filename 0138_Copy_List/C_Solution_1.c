//C Solution (1) to Leetcode.138
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct MapNode {
    struct Node* orig;
    struct Node* refl;
    struct MapNode* next;
};

struct Map {
    int mapSize;
    struct MapNode** list;
};

typedef struct Map* ReflectionMap;

ReflectionMap CreateReflMap(){
    ReflectionMap map = (ReflectionMap)malloc(sizeof(struct Map));
    map->mapSize = 100;
    map->list = (struct MapNode**)malloc(sizeof(struct MapNode*) * map->mapSize);
    for(int i = 0; i < map->mapSize; i++){
        map->list[i] = NULL;
    }
    return map;
}

void InsertReflection(ReflectionMap map, struct Node* orig, struct Node* refl){
    int addr = abs(orig->val) % map->mapSize;
    struct MapNode* newNode = (struct MapNode*)malloc(sizeof(struct MapNode));
    newNode->orig = orig;
    newNode->refl = refl;
    newNode->next = map->list[addr];
    map->list[addr] = newNode;
}

struct Node* Reflection(ReflectionMap map, struct Node* orig){
    if(!orig){
        return NULL;
    }
    int addr = abs(orig->val) % map->mapSize;
    struct MapNode* ptr = map->list[addr];
    while(ptr){
        if(ptr->orig == orig){
            return ptr->refl;
        }
        ptr = ptr->next;
    }
    return NULL;
}

struct Node* copyRandomList(struct Node* head){
    if(!head){
        return NULL;
    }
    ReflectionMap map = CreateReflMap();
    struct Node* cloneHead = (struct Node*)malloc(sizeof(struct Node));
    cloneHead->val = head->val;
    cloneHead->next = NULL;
    InsertReflection(map, head, cloneHead);
    struct Node* p = head->next;
    struct Node* cp = cloneHead;
    while(p){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = p->val;
        newNode->next = NULL;
        cp->next = newNode;
        InsertReflection(map, p, newNode);
        cp = cp->next;
        p = p->next;
    }
    p = head;
    cp = cloneHead;
    while(p){
        cp->random = Reflection(map, p->random);
        p = p->next;
        cp = cp->next;
    }
    return cloneHead;
}

//TestBench
