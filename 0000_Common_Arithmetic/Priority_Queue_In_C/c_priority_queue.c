/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#include "c_priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct HeapStruct {
	int size;
	int capacity;
	ELEMENTTYPE* elements;
} Heap;

PQueue queue_init(int MaxElements) {
	PQueue new_queue = (PQueue)malloc(sizeof(Heap));
	if (new_queue == NULL) {
		printf("Not enough space.\n");
		return NULL;
	}
	ELEMENTTYPE* data = (ELEMENTTYPE*)malloc(sizeof(ELEMENTTYPE) * (MaxElements + 1));
	if (data == NULL) {
		printf("Not enough space.\n");
		return NULL;
	}
	new_queue->size = 0;
	new_queue->capacity = MaxElements;
	new_queue->elements = data;
	new_queue->elements[0] = _MIN;
	queue_empty(new_queue);				//Is this neccessary?
	return new_queue;
}

PQueue queue_build(ELEMENTTYPE* data, int count, int MaxElements) {
	PQueue queue = queue_init(MaxElements);
	for (Position p = 1; p <= count; p++) {
		queue->elements[p] = data[p - 1];
		queue->size++;
	}
	/*
	Notes:
	下述for循环步进条件为p--而不是p /= 2
	代表从树形结构倒数第二行最后一个开始下滤，并将该层每一个节点都进行下滤
	通过p--可以从右向左，从下到上遍历树形结构，达到依次下滤
	而如果采用p /= 2则没办法做到逐层下滤
	*/
	for (Position p = queue->size / 2; p > 0; p--)
		queue_percolate_down(p, queue);
	return queue;
}

void queue_free(PQueue queue) {
	if (queue == NULL) {
		printf("Not a queue.\n");
		return;
	}
	free(queue->elements);
	free(queue);
}

void queue_empty(PQueue queue) {
	if (queue == NULL) {
		printf("Not a queue.\n");
		return;
	}
	for (Position p = queue->capacity; p > 0; p--){
		queue->elements[p] == _MAX;
	}
	queue->size = 0;
}

void queue_insert(PQueue queue, ELEMENTTYPE value){
	if(queue->size == queue->capacity){
		printf("The queue is full.\n");
		return;
	}
	queue->elements[++queue->size] = value;
	queue_percolate_up(queue->size, queue);
}

ELEMENTTYPE queue_delete_min(PQueue queue){
	if(queue == NULL){
		printf("Not a queue.\n");
		return _MIN;
	}
	if(queue->size == 0){
		printf("Empty queue.\n");
		return _MIN;
	}
	int min = queue->elements[1];
	queue->elements[1] = _MAX;
	Position p = queue_percolate_down(1, queue);
	queue->elements[p] = queue->elements[queue->size];
	queue->elements[queue->size--] = _MAX;
	return min;
}

ELEMENTTYPE queue_get_min(PQueue queue){
	if(queue == NULL){
		printf("Not a queue.\n");
		return _MIN;
	}
	if(queue->size == 0){
		printf("Empty queue.\n");
		return _MIN;
	}
	return queue->elements[1];
}

Position queue_percolate_down(Position p, PQueue queue){
	//Verify if the queue is empty
	if(queue == NULL){
		printf("Not a queue.\n");
		return 0;
	}
	if(p > queue->size){
		printf("Position out of edge while percolating down.\n");
		return 0;
	}
	while(2 * p <= queue->size){
		//Make a copy of father
		int parent = queue->elements[p];
		//Move the iterator to the left child
		p *= 2;
		//Select the min between the two childs and make a copy of that
		if(p < queue->size && queue->elements[p + 1] < queue->elements[p])
			p++;
		int child = queue->elements[p];
		//Swap
		if(parent > child){
			queue->elements[p] = parent;
			queue->elements[p / 2] = child;
		}
	}
	return p;
}

Position queue_percolate_up(Position p, PQueue queue){
	//Verify if the queue is empty
	if(queue == NULL){
		printf("Not a queue.\n");
		return 0;
	}
	if(p > queue->size || p < 1){
		printf("Position out of edge while percolating up.\n");
		return 0;
	}
	//Make copy of parent and child
	int parent;
	int child;
	while (queue->elements[p / 2] > queue->elements[p]){
		//Swap
		parent = queue->elements[p / 2];
		child = queue->elements[p];
		queue->elements[p / 2] = child;
		queue->elements[p] = parent;
		p /= 2;
	}
	return p;
}

void queue_decrease_key(Position p, ELEMENTTYPE delta, PQueue queue){
	if(queue == NULL){
		printf("Not a queue.\n");
		return;
	}
	if(p > queue->size || p < 1){
		printf("Position out of edge while decreasing key.\n");
		return;
	}
	//decrease key
	queue->elements[p] -= delta;
	//percolate up
	queue_percolate_up(p, queue);
}

void queue_increase_key(Position p, ELEMENTTYPE delta, PQueue queue){
	if(queue == NULL){
		printf("Not a queue.\n");
		return;
	}
	if(p > queue->size || p < 1){
		printf("Position out of edge while decreasing key.\n");
		return;
	}
	//increase key
	queue->elements[p] += delta;
	//percolate down
	queue_percolate_down(p, queue);
}

void queue_delete(Position p, PQueue queue){
	//Increase key to max
	queue_decrease_key(p, queue->elements[p] - _MIN, queue);
	//Delete min
	queue_delete_min(queue);
}

void queue_print(PQueue queue, Position p, int depth){
	if(p < 1 || p > queue->size)
		return;
	if(p * 2 < queue->size){
		queue_print(queue, p * 2 + 1, depth + 1);
	}
	int iterator = depth;
	while(iterator > 0){
		printf("\t");
		iterator--;
	}
	printf(ET, queue->elements[p]);
	printf("\n");
	if(p * 2 <= queue->size){
		queue_print(queue, p * 2, depth + 1);
	}
}