/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 10:28:36
 * LastEditTime : 2022-02-06 10:50:52
 * Description  : [Weekly 279] | C
 */

/**
 * Your Bitset struct will be instantiated and called as such:
 * Bitset* obj = bitsetCreate(size);
 * bitsetFix(obj, idx);
 
 * bitsetUnfix(obj, idx);
 
 * bitsetFlip(obj);
 
 * bool param_4 = bitsetAll(obj);
 
 * bool param_5 = bitsetOne(obj);
 
 * int param_6 = bitsetCount(obj);
 
 * char * param_7 = bitsetToString(obj);
 
 * bitsetFree(obj);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool* bits;
    bool reversed;
    int size;
    int count;
} Bitset;


Bitset* bitsetCreate(int size) {
    Bitset* set = (Bitset*)malloc(sizeof(Bitset));
    set->bits = (bool*)malloc(sizeof(bool) * size);
    for(int i = 0; i < size; i++){
        set->bits[i] = false;
    }
    set->size = size;
    set->count = 0;
    set->reversed = false;
    return set;
}

void bitsetFix(Bitset* obj, int idx) {
    if(!(obj->reversed ^ obj->bits[idx])){
        obj->count++;
    }
    obj->bits[idx] = obj->reversed ? false : true;
}

void bitsetUnfix(Bitset* obj, int idx) {
    if(obj->reversed ^ obj->bits[idx]){
        obj->count--;
    }
    obj->bits[idx] = obj->reversed ? true : false;
}

void bitsetFlip(Bitset* obj) {
    obj->reversed = !obj->reversed;
    obj->count = obj->size - obj->count;
}

bool bitsetAll(Bitset* obj) {
    return obj->count == obj->size;
}

bool bitsetOne(Bitset* obj) {
    return obj->count > 0;
}

int bitsetCount(Bitset* obj) {
    return obj->count;
}

char * bitsetToString(Bitset* obj) {
    char* str = (char*)malloc(sizeof(char) * (obj->size + 1));
    for(int i = 0; i < obj->size; i++){
        str[i] = (obj->reversed ^ obj->bits[i]) ? '1' : '0';
    }
    str[obj->size] = '\0';
    return str;
}

void bitsetFree(Bitset* obj) {
    for(int i = 0; i < obj->size; i++){
        obj->bits[i] = false;
    }
    obj->count = 0;
    obj->reversed = false;
}