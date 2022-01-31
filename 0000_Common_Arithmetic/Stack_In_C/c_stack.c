/*
Jonathan Zhang (Linloir) @ 2021-6-3
*/

#include <stdlib.h>
#include <stdio.h>
#include "c_stack.h"

int Stack_Is_Empty(Stack s){
    return s->next == NULL;
}

Stack Stack_Create(void){
    Stack new_stack = (Stack)malloc(sizeof(Node));
    if(new_stack == NULL)       //Out of space
    {
        printf("No more space\n");
        return NULL;
    }
    new_stack->next = NULL;
    Stack_Empty(new_stack);
    return new_stack;
}

int Stack_Empty(Stack s){
    if(s == NULL)
        return -2;      //Need to create stack first
    while(!Stack_Is_Empty(s)){
        Stack_Pop(s);
    }
    return 0;
}

int Stack_Push(Stack s, char value){
    PtrToNode new_node = (PtrToNode)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("No more space\n");
        return -3;      //No more space
    }
    new_node->value = value;
    new_node->next = s->next;
    s->next = new_node;
    return 0;
}

int Stack_Pop(Stack s){
    if(s == NULL)
        return -4;      //No stack here
    if(s->next == NULL)
        return -5;      //Nothing to pop
    PtrToNode tmp = s->next;
    s->next = tmp->next;
    free(tmp);
    return 0;
}

char Stack_Top(Stack s){
    if(Stack_Is_Empty(s)){
        return -5;
    }
    return s->next->value;
}

void Stack_Free(Stack s){
    if(s != NULL){
        while(!Stack_Is_Empty(s)){
            PtrToNode tmp = s->next;
            s->next = tmp->next;
            free(tmp);
        }
        free(s);
    }
}