/*
Jonathan Zhang (Linloir) @ 2021-6-3
*/

#include <stdio.h>
#include "c_stack.h"

int main(){
    Stack sample_stack = Stack_Create();
    int exit = 0;
    int elements = 0;
    printf("Commands: [number] | grammar | function\n");
    printf("[1] | 1 <value> | 1Push into stack\n");
    printf("[2] | 2 | Get the top value\n");
    printf("[3] | 3 | Pop the last value\n");
    printf("[0] | 0 | exit\n");
    while(!exit){
        int command = -1;
        scanf("%d", &command);
        if(command == 1){
            char value;
            scanf("%*c%c", &value);
            int err = Stack_Push(sample_stack, value);
            if(err == -3){
                printf("Pushed 0 elements, no more space.\n");
                continue;
            }
            elements++;
            printf("Pushed 1 elements, now there are %d elements.\n", elements);
            continue;
        }
        else if(command == 2){
            char err = Stack_Top(sample_stack);
            if(err == -5){
                printf("There is nothing in the stack.\n");
            }
            else{
                printf("The Top value is %c\n", Stack_Top(sample_stack));
            }
            continue;
        }
        else if(command == 3){
            int err = Stack_Pop(sample_stack);
            if(err == -4){
                printf("Something went wrong with the stack.\n");
                exit = 1;
            }
            else if(err == -5)
                printf("The stack is empty, nothing to pop.\n");
            else
                printf("Poped out 1 elements, there are %d left.\n", --elements);
        }
        else{
            printf("Exiting...\n");
            exit = 1;
        }
    }
    return 0;
}