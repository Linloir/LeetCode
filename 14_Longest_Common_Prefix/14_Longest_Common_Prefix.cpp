/*
Jonathan Zhang (Linloir) @ 2021-6-2
Time:   4ms
Memory: 5.8Mb
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 1)
		return strs[0];
	int max = 0;
	for (int i = 0; i < strlen(strs[0]) && i < strlen(strs[1]); i++) {
		if (strs[0][i] != strs[1][i])
			break;
		max++;
	}
	for (int i = 2; i < strsSize; i++) {
		int valid = true;
		for (int j = 0; j < max; j++) {
			if (strs[i][j] != strs[0][j]) {
				max = j;
				break;
			}
		}
	}
	char* output = (char*)malloc(sizeof(char) * (max + 2));

//!	Easy to make mistakes:
//! 	memset overflow!
	memset(output, 0, sizeof(char) * (max + 2));

//! Easy to make mistakes:
//! 	strncpy(DESTINATION, SOURCE, NUM)
	strncpy(output, strs[0], max);
	return output;
}

int main() {
	char a[255] = "a";
	char** strs = (char**)malloc(sizeof(char*) * 1);
	strs[0] = a;
	char* output = longestCommonPrefix(strs, 1);
	printf("%s", output);
	return 0;
}