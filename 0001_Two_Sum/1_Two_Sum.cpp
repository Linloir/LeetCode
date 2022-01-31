/*
Jonathan Zhang (Linloir) @ 2021-6-2
time:	12ms
memory:	6.8Mb
*/

#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <vector>

using namespace std;

typedef struct HASH_DATA {
	int key;
	int data;
	struct HASH_DATA* next;
} hash_data;

typedef struct HASH_TABLE {
	hash_data** head;
	int hash_width;
} hash_table;

int hash_init(hash_table* table, int width) {
	if (width <= 0)
		return -1;
	hash_data** head = (hash_data**)malloc(sizeof(hash_data*) * width);
	if (head == NULL)
		return -1;
	table->head = head;
	memset(table->head, 0, sizeof(hash_data*) * width);
	table->hash_width = width;
	return 0;
}

int hash_addr(hash_table* table, int key) {
	int addr = abs(key) % table->hash_width;
	return addr;
}

int hash_insert(hash_table* table, int key, int data) {
	hash_data* new_data = (hash_data*)malloc(sizeof(hash_data));
	if (new_data == NULL)
		return -1;
	new_data->data = data;
	new_data->key = key;
	int pos = hash_addr(table, key);
	new_data->next = table->head[pos];
	table->head[pos] = new_data;
	return 0;
}

hash_data* hash_find_and_erase(hash_table* table, int key) {
	int pos = hash_addr(table, key);
	hash_data* iterator = table->head[pos];
	if (iterator != NULL && iterator->key == key) {
		hash_data* result = iterator;
		table->head[pos] = iterator->next;
		return result;
	}
	while (iterator != NULL && iterator->next != NULL) {
		if (iterator->next->key == key) {
			hash_data* result = iterator->next;
			iterator->next = iterator->next->next;
			return result;
		}
		iterator = iterator->next;
	}
	return NULL;
}

void hash_free(hash_table* table) {
	for (int i = 0; i < table->hash_width; i++) {
		hash_data* iterator = table->head[i];
		while (iterator != NULL) {
			hash_data* temp = iterator->next;
			free(iterator);
			iterator = temp;
		}
	}
	free(table->head);
	free(table);
}

hash_data* hash_find(hash_table* table, int key) {
	int k = hash_addr(table, key);
	hash_data* element_head = table->head[k];
	while (element_head != NULL) {
		if (element_head->key == key) {
			return element_head;
		}
		element_head = element_head->next;
	}
	return NULL;
}

vector<int> TwoSum(vector<int>& nums, int target) {
	vector<int> result;
	result.resize(2);
	hash_table* new_table = (hash_table*)malloc(sizeof(hash_table));
	hash_init(new_table, 100);
	for (int i = 0; i < nums.size(); i++) {
		hash_data* a = hash_find(new_table, target - nums[i]);
		if (a != NULL) {
			result[0] = a->data;
			result[1] = i;
			return result;
		}
		hash_insert(new_table, nums[i], i);
	}
	return result;
}

int main() {
	vector<int> test;
	test.push_back(2);
	test.push_back(7);
	test.push_back(11);
	test.push_back(15);
	int target = 9;
	vector<int> result;
	result = TwoSum(test, target);
	cout << result[0] << result[1] << endl;
}