/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#ifndef _C_LINKED_LIST_
#define _C_LINKED_LIST_

typedef int ElementType;

typedef struct Node Node;
typedef Node *List;
typedef List PtrToNode;
typedef List Position;

List list_create();
void list_free(List l);
void list_insert(Position p, ElementType value);    //Insert value after p
void list_delete(List l, ElementType value);
int list_is_last(Position p);
Position list_find(List l, ElementType value);
Position list_find_previous(List l, ElementType value);
void list_print(List l);

#endif