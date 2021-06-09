/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#include "c_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/*
In this implementation, a linked list WITH a header is created.
*/

struct Node{
    ElementType value;
    PtrToNode next;
};

List list_create(){
    List new_list = (List)malloc(sizeof(Node));
    if(new_list == NULL){
        printf("Not enough space.\n");
        return NULL;
    }
    new_list->value = 0;
    new_list->next = NULL;
    return new_list;
}

void list_free(List l){
    if (l == NULL)
        return;
    if (!list_is_last(l))
        list_free(l->next);
    free(l);
}

void list_insert(Position p, ElementType value){
    PtrToNode new_node = (PtrToNode)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Not enough space.\n");
        return;
    }
    new_node->value = value;
    new_node->next = p->next;
    p->next = new_node;
}

void list_delete(List l, ElementType value){
    Position p = list_find_previous(l, value);
    if(p == NULL){
        printf("Value not found in the list.\n");
        return;
    }
    Position target = p->next;
    p->next = target->next;
    free(target);
}

int list_is_last(Position p){
    if(p == NULL)
        return 1;
    return p->next == NULL;
}

Position list_find(List l, ElementType value){
    Position iterator = l;
    while(iterator != NULL){
        if(iterator->value == value)
            break;
        iterator = iterator->next;
    }
    return iterator;    //Will return NULL if not found.
}

Position list_find_previous(List l, ElementType value){
    Position iterator = l;
    while(iterator->next != NULL){
        if(iterator->next->value == value)
            return iterator;
        iterator = iterator->next;
    }
    return NULL;
}

void list_print(List l){
    if(list_is_last(l))
        return;
    Position iterator = l->next;
    while(iterator->next != NULL){
        printf("%d -> ", iterator->value);
        iterator = iterator->next;
    }
    printf("%d\n", iterator->value);
}