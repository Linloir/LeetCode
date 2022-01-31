/*
Jonathan Zhang (Linloir) @ 2021-6-2
Time:   24ms
Memory: 7.1Mb
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
	char value;
	struct Node* nextNode;
} node;

typedef struct Node* Stack;
typedef struct Node* PtrToNode;

void stack_init(Stack s) {
	s->value = 0;
	s->nextNode = NULL;
}

void stack_push(Stack s, char c) {
	PtrToNode in = (PtrToNode)malloc(sizeof(Node));
	in->value = c;
	PtrToNode tmp = s->nextNode;
	s->nextNode = in;
	in->nextNode = tmp;
}

char stack_get(Stack s) {
	return s->nextNode->value;
}

char stack_pop(Stack s) {
	char value = stack_get(s);
	PtrToNode tmp = s->nextNode;
	s->nextNode = tmp->nextNode;
	free(tmp);
	return value;
}

bool stack_is_last(Stack s) {
	bool valid = s->nextNode == NULL;
	return s->nextNode == NULL;
}

int get_roman_value(char c) {
	switch (c) {
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	default:return 0;
	}
}

int romanToInt(char* s) {
	Stack new_stack = (Stack)malloc(sizeof(Node));
	stack_init(new_stack);

	int result = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (i > 0 && !stack_is_last(new_stack) && get_roman_value(s[i]) > get_roman_value(stack_get(new_stack))) {
			result = result + get_roman_value(s[i]) - get_roman_value(stack_pop(new_stack));
			continue;
		}
		stack_push(new_stack, s[i]);
	}
	while (!stack_is_last(new_stack)) {
		result += get_roman_value(stack_pop(new_stack));
	}
	return result;
}

int main() {
	char s[] = "CIXIV";
	int result = romanToInt(s);
	printf("%d", result);
	return 0;
}