/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#ifndef _C_PRIORITY_QUEUE_
#define _C_PRIORITY_QUEUE_

#define _MAX 65565
#define _MIN -65565
#define ET "%d"

/*
Notes:
堆本身需要用结构体表示，但是堆内存储元素的结构可以使用数组！
*/

struct HeapStruct;
typedef int ELEMENTTYPE;
typedef int Position;
typedef struct HeapStruct *PQueue;

PQueue queue_init(int MaxElements);
PQueue queue_build(ELEMENTTYPE* data, int count, int MaxElements);
void queue_free(PQueue queue);
void queue_empty(PQueue queue);
void queue_insert(PQueue queue, ELEMENTTYPE value);
ELEMENTTYPE queue_delete_min(PQueue queue);
ELEMENTTYPE queue_get_min(PQueue queue);
Position queue_percolate_down(Position p, PQueue queue);
Position queue_percolate_up(Position p, PQueue queue);
void queue_decrease_key(Position p, ELEMENTTYPE delta, PQueue queue);
void queue_increase_key(Position p, ELEMENTTYPE delta, PQueue queue);
void queue_delete(Position p, PQueue queue);
void queue_print(PQueue queue, Position p, int depth);

#endif