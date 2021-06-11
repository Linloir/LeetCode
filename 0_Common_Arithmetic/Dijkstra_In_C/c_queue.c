#include "c_queue.h"
#include <stdio.h>
#include <stdlib.h>

int q_head = 0;
int q_tail = 0;

Queue queue_init(){
    Queue new_queue = (Queue)malloc(sizeof(int) * MAX_QUEUE);
    for (int i = 0; i < MAX_QUEUE; i++){
        new_queue[i] = _QUEUE_NOT_ASSIGNED;
    }
    return new_queue;
}

void queue_enqueue(Queue queue, int value){
    if(q_tail == q_head && !queue_is_empty(queue)){
        printf("Full.\n");
        return;
    }
    queue[q_tail] = value;
    q_tail = q_tail == MAX_QUEUE - 2 ? 0 : q_tail + 1;
}

int queue_dequeue(Queue queue){
    int out = queue[q_head];
    queue[q_head] = _QUEUE_NOT_ASSIGNED;
    q_head = q_head == MAX_QUEUE - 2 ? 0 : q_head + 1;
    return out;
}

int queue_is_empty(Queue queue){
    return q_head == q_tail && queue[q_head] == _QUEUE_NOT_ASSIGNED;
}