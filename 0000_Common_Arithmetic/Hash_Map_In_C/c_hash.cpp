/*
Source code from LeetCode @ ChenXin
https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-san-chong-jie-fa-by-chen-xing-15/

Edited by Jonathan Zhang (Linloir) @ 2021-6-2
*/

#include "c_hash.h"

///Initiate
int hash_init(struct hash_table* table, int width) {
    if (width <= 0)
        return -1;
    struct hash_data** tmp = (hash_data**)malloc(sizeof(struct hash_data*) * width);
    if (table->head == NULL)
        return -1;
    table->head = tmp;
    memset(table->head, 0, width * sizeof(struct hash_data*));
    table->hash_width = width;
    return 0;
}

///Release
void hash_free(struct hash_table table) {
    if (table.head != NULL) {
        for (int i = 0; i < table.hash_width; i++) {
            struct hash_data* element_head = table.head[i];
            while (element_head != NULL) {
                struct hash_data* temp = element_head;
                element_head = element_head->next;
                free(temp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.hash_width = 0;
}

int hash_addr(struct hash_table table, int key) {
    int addr = abs(key) % table.hash_width;
    return addr;
}

///Add
int hash_insert(struct hash_table table, int key, int value) {
    struct hash_data* tmp = (hash_data*)malloc(sizeof(struct hash_data));
    if (tmp == NULL)
        return -1;
    tmp->key = key;
    tmp->data = value;
    int k = hash_addr(table, key);
    tmp->next = table.head[k];
    table.head[k] = tmp;
    return 0;
}

///Find
struct hash_data* hash_find(struct hash_table table, int key) {
    int k = hash_addr(table, key);
    struct hash_data* element_head = table.head[k];
    while (element_head != NULL) {
        if (element_head->key == key) {
            return element_head;
        }
        element_head = element_head->next;
    }
    return NULL;
}

struct hash_data* hash_find_and_erase(struct hash_table table, int key) {
    int k = hash_addr(table, key);
    struct hash_data* iterator = table.head[k];
    if (iterator->key == key) {
        table.head[k] = iterator->next;
        return iterator;
    }
    while (iterator->next != NULL) {
        if (iterator->next->key == key) {
            hash_data* tmp = iterator->next;
            iterator->next = iterator->next->next;
            return tmp;
        }
        iterator = iterator->next;
    }
    return NULL;
}