#ifndef _C_QUEUE_
#define _C_QUEUE_

#define MAX_QUEUE 255
#define _QUEUE_NOT_ASSIGNED 65535

typedef int *Queue;

Queue queue_init();
void queue_enqueue(Queue queue, int value);
int queue_dequeue(Queue queue);
int queue_is_empty(Queue queue);

#endif