/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#include "c_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List sample_list = list_create();
    int exit = 1;
    int command = 0;
    printf("Commands:\n");
    printf("[0] | Exit\n");
    printf("[1] | Insert value\n");
    printf("[2] | Insert value after value\n");
    printf("[3] | Delete value\n");
    while(exit){
        scanf("%d", &command);
        switch(command){
            case 0:
                exit = 0;
                break;
            case 1:{
                int value;
                scanf("%d", &value);
                list_insert(sample_list, value);
                printf("======================\n");
                list_print(sample_list);
                printf("======================\n");
                break;
            }
            case 2:{
                int value, p_value;
                scanf("%d %d", &value, &p_value);
                Position p = list_find(sample_list, p_value);
                if(p == NULL){
                    printf("Not found in the list.\n");
                    break;
                }
                list_insert(p, value);
                printf("======================\n");
                list_print(sample_list);
                printf("======================\n");
                break;
            }
            case 3:{
                int value;
                scanf("%d", &value);
                list_delete(sample_list, value);
                printf("======================\n");
                list_print(sample_list);
                printf("======================\n");
                break;
            }
            default:
                exit = 0;
        }
    }
    return 0;
}