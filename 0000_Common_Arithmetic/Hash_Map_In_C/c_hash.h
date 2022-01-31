/*
Code from LeetCode @ ChenXin
https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-san-chong-jie-fa-by-chen-xing-15/

Edited by Jonathan Zhang (Linloir) @ 2021-6-2
*/

#pragma once
#ifndef _C_HASH_
#define _C_HASH_
#include <memory.h>
#include <stdlib.h>

struct hash_data {
    int key;
    int data;
    struct hash_data* next;
};

struct hash_table
{
    struct hash_data** head;
    int hash_width;
};

int hash_init(struct hash_table* table, int width);
void hash_free(struct hash_table table);
int hash_addr(struct hash_table table, int key);
int hash_insert(struct hash_table table, int key, int value);
struct hash_data* hash_find(struct hash_table table, int key);
struct hash_data* hash_find_and_erase(struct hash_table table, int key);

#endif