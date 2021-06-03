/*
Jonathan Zhang (Linloir) @ 2021-6-3
*/

#ifndef _C_STACK_
#define _C_STACK_

struct node{
    char value;
    struct node *next;
};

typedef struct node Node;
typedef struct node *PtrToNode;
typedef struct node *Stack;

int Stack_Is_Empty(Stack);   //Judge whether the stack is empty
Stack Stack_Create(void);    //Create a new stack
int Stack_Empty(Stack);      //Make a stack empty
int Stack_Push(Stack, char); //Push a new value into the stack
int Stack_Pop(Stack);       //Pop out the top element of a stack
char Stack_Top(Stack);       //Return the top value of a stack
void Stack_Free(Stack);      //Free a stack

#endif