/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
//Excellent!!!!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct data {
    int key;
    int val;
    int nextSlot;
    int prevSlot;
    int lruSlot;
    int mruSlot;
};

typedef struct {
    int capacity;
    struct data* cache;
    int* table;
    int lruSlot;
    int mruSlot;
} LRUCache;

void AccessSlot(LRUCache* obj, int slot){
    if(slot == obj->mruSlot){
        return;
    }
    if(slot == obj->lruSlot)
        obj->lruSlot = obj->cache[slot].mruSlot;
    int lruSlot = obj->cache[slot].lruSlot;
    int mruSlot = obj->cache[slot].mruSlot;
    if (lruSlot != -1)
        obj->cache[lruSlot].mruSlot = mruSlot;
    obj->cache[mruSlot].lruSlot = lruSlot;
    obj->cache[obj->mruSlot].mruSlot = slot;
    obj->cache[slot].lruSlot = obj->mruSlot;
    obj->cache[slot].mruSlot = obj->capacity;
    obj->mruSlot = slot;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* newCache = (LRUCache*)malloc(sizeof(LRUCache));
    newCache->capacity = capacity;
    newCache->cache = (struct data*)malloc(sizeof(struct data) * capacity);
    newCache->table = (int*)malloc(sizeof(int) * capacity);
    for(int i = 0; i < capacity; i++){
        newCache->table[i] = -1;
        newCache->cache[i].key = -1;
        newCache->cache[i].val = -1;
        newCache->cache[i].lruSlot = i - 1;
        newCache->cache[i].mruSlot = i + 1;
        newCache->cache[i].prevSlot = -1;
        newCache->cache[i].nextSlot = -1;
    }
    newCache->lruSlot = 0;
    newCache->mruSlot = capacity - 1;
    return newCache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    //printf("Get operation\n");
    //printf("Cache has lru %d, mru %d\n", obj->lruSlot, obj->mruSlot);
    int addr = key % obj->capacity;
    int slot = obj->table[addr];
    while(slot != -1){
        if(obj->cache[slot].key == key){
            AccessSlot(obj, slot);
            //printf("Cache now has lru %d, mru %d\n", obj->lruSlot, obj->mruSlot);
            return obj->cache[slot].val;
        }
        else{
            slot = obj->cache[slot].nextSlot;
        }
    }
    //printf("Cache now has lru %d, mru %d\n", obj->lruSlot, obj->mruSlot);
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    //printf("Put operation\n");
    //printf("Cache has lru %d, mru %d\n", obj->lruSlot, obj->mruSlot);
    int addr = key % obj->capacity;
    int slot = obj->table[addr];
    while(slot != -1){
        if(obj->cache[slot].key == key){
            AccessSlot(obj, slot);
            obj->cache[slot].val = value;
            return;
        }
        else{
            slot = obj->cache[slot].nextSlot;
        }
    }
    slot = obj->lruSlot;
    //printf("Putting val %d in slot %d\n", value, slot);
    //printf("Slot originally has lru %d, mru %d, key %d, val %d\n", obj->cache[slot].lruSlot, obj->cache[slot].mruSlot, obj->cache[slot].key, obj->cache[slot].val);
    //Adjust old addr
    int prevSlot = obj->cache[slot].prevSlot;
    int nextSlot = obj->cache[slot].nextSlot;
    if(prevSlot == -1){
        if(obj->cache[slot].key != -1){
            obj->table[obj->cache[slot].key % obj->capacity] = nextSlot;
            if(nextSlot != -1)
                obj->cache[nextSlot].prevSlot = prevSlot;
        }
    }
    else{
        obj->cache[prevSlot].nextSlot = nextSlot;
        if(nextSlot != -1)
            obj->cache[nextSlot].prevSlot = prevSlot;
    }
    //Insert new information
    obj->cache[slot].key = key;
    obj->cache[slot].val = value;
    obj->cache[slot].nextSlot = obj->table[key % obj->capacity];
    if(obj->cache[slot].nextSlot != -1)
        obj->cache[obj->cache[slot].nextSlot].prevSlot = slot;
    obj->cache[slot].prevSlot = -1;
    obj->table[key % obj->capacity] = slot;
    AccessSlot(obj, slot);
    //printf("Slot now has lru %d, mru %d, key %d, val %d\n", obj->cache[slot].lruSlot, obj->cache[slot].mruSlot, obj->cache[slot].key, obj->cache[slot].val);
    //printf("Cache now has lru %d, mru %d\n", obj->lruSlot, obj->mruSlot);
}

void lRUCacheFree(LRUCache* obj) {
    for(int i = 0; i < obj->capacity; i++){
        obj->table[i] = -1;
        obj->cache[i].key = -1;
        obj->cache[i].val = -1;
        obj->cache[i].lruSlot = i - 1;
        obj->cache[i].mruSlot = i + 1;
        obj->cache[i].prevSlot = -1;
        obj->cache[i].nextSlot = -1;
    }
    obj->lruSlot = 0;
    obj->mruSlot = obj->capacity - 1;
}

//TestBench
void TestBench(){
    LRUCache* cache = lRUCacheCreate(2);
    int res;
    lRUCachePut(cache, 2, 1);
    printf("null,");
    lRUCachePut(cache, 2, 2);
    printf("null,");
    res = lRUCacheGet(cache, 2);
    printf("%d,", res);
    lRUCachePut(cache, 1, 1);
    printf("null,");
    lRUCachePut(cache, 4, 1);
    printf("null,");
    res = lRUCacheGet(cache, 2);
    printf("%d,", res);
}

int main(){
    TestBench();
    return 0;
}