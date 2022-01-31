/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   4ms
Memory: 5.8Mb
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h> 

struct node{
    char value;
    struct node *next;
};

typedef struct node Node;
typedef struct node *PtrToNode;
typedef struct node *Stack;

Stack stack_init(void);
int stack_is_empty(Stack);
int stack_empty(Stack);
int stack_pop(Stack);
char stack_top(Stack);
int stack_push(Stack, char);

Stack stack_init(void){
    Stack new_stack = (Stack)malloc(sizeof(Node));
    new_stack->next = NULL;
    stack_empty(new_stack);
    return new_stack;
}

int stack_is_empty(Stack s){
    return s->next == NULL;
}

int stack_empty(Stack s){
    if(s == NULL)
        return -1;
    while(!stack_is_empty(s))
        stack_pop(s);
    return 0;
}

int stack_pop(Stack s){
    if(!stack_is_empty(s)){
        PtrToNode tmp = s->next;
        s->next = s->next->next;
        free(tmp);
    }
    return 0;
}

char stack_top(Stack s){
    if(!stack_is_empty(s))
        return s->next->value;
    return NULL;
}

int stack_push(Stack s, char value){
    PtrToNode new_node = (PtrToNode)malloc(sizeof(Node));
    if(new_node == NULL)
        return -1;
    new_node->value = value;
    new_node->next = s->next;
    s->next = new_node;
    return 0;
}

bool isValid(char * s){
    int len = strlen(s);
    Stack stack = stack_init();
    int i = 0;
    while(i < len){
        if(s[i] == ')'){
            if(stack_top(stack) == '(')
                stack_pop(stack);
            else
                return false;
        }
        else if(s[i] == ']'){
            if(stack_top(stack) == '[')
                stack_pop(stack);
            else
                return false;
        }
        else if(s[i] == '}'){
            if(stack_top(stack) == '{')
                stack_pop(stack);
            else
                return false;
        }
        else{
            stack_push(stack, s[i]);
        }
        i++;
    }
    return stack_is_empty(stack);
}

int main(){
    char test[] = "[(([({})]())[])]";
    printf("%s", isValid(test) ? "True" : "False");
    return 0;
}