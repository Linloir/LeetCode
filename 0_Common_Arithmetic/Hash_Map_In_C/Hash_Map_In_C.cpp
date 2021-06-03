#define _CRT_SECURE_NO_WARNINGS

/*
Sample of using hash map in C to find the position of any key in an array.
Sample by Jonathan Zhang (Linloir) @ 2021-6-2
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "c_hash.h"

void set_data(int* data, int width) {
	srand(20210602);
	for (int i = 0; i < width; i++) {
		data[i] = rand() % 50 - 25;
	}
}

void print_data(int* data, int width) {
	printf("Sample data set as:\n[");
	for (int i = 0; i < width-1; i++) {
		printf("%d,", data[i]);
	}
	printf("%d]\n", data[width - 1]);
}

int get_mark(hash_table sample_table, int key) {
	hash_data* answer = hash_find_and_erase(sample_table, key);
	if (answer == NULL)
		return -1;
	int ans = answer->data;
	free(answer);
	return ans;
}

void Test_C_Hash() {
	int sample_data[50];
	set_data(sample_data, 50);
	print_data(sample_data, 50);

	hash_table sample_table;
	hash_init(&sample_table, 10);

	for (int i = 0; i < 50; i++)
		hash_insert(sample_table, sample_data[i], i);

	int test_cases = 10;
	while (test_cases--) {
		printf("Insert data you want:\n");
		int test_data;
		if (scanf("%d", &test_data) != 1) {
			printf("Wrong input\n");
			while (getchar() != '\n');
			continue;
		}
		int position = get_mark(sample_table, test_data);
		if (position >= 0)
			printf("%d is at position %d\n", test_data, position);
		else
			printf("There is no more %d in data\n", test_data);
	}
}

int main() {
	Test_C_Hash();
	return 0;
}