/*
Jonathan Zhang (Linloir) @ 2021-6-9
*/

#include "c_priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    PQueue sample_queue_1;
    ELEMENTTYPE data[10] = {1, 3, 5, 2, 7, 45, 15, 4, 52, 6};
    sample_queue_1 = queue_build(data, 10, 25);
    printf("Sample heap 1:\n");
    printf("===================\n");
    queue_print(sample_queue_1, 1, 0);
    printf("===================\n");

    PQueue sample_queue_2 = queue_init(256);
    int exit = 1;
    int command = 0;
    printf("Commands:\n");
    printf("[0] | exit\n");
    printf("[1] | add value to heap\n");
    printf("[2] | return min value\n");
    printf("[3] | delete and return min\n");
    printf("[4] | increase key at position p\n");
    printf("[5] | decrease key at position p\n");
    printf("[6] | delete value at position p\n");
    printf("[7] | print queue one more time\n");
    while(exit){
        scanf("%d", &command);
        switch(command){
            case 0:{
                exit = 0;
                break;
            }
            case 1:{
                ELEMENTTYPE value;
                scanf(ET, &value);
                queue_insert(sample_queue_2, value);
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            case 2:{
                printf("%d\n", queue_get_min(sample_queue_2));
                break;
            }
            case 3:{
                queue_delete_min(sample_queue_2);
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            case 4:{
                int p, delta;
                scanf("%d %d", &p, &delta);
                queue_increase_key(p, delta, sample_queue_2);
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            case 5:{
                int p, delta;
                scanf("%d %d", &p, &delta);
                queue_decrease_key(p, delta, sample_queue_2);
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            case 6:{
                int p;
                scanf("%d", &p);
                queue_delete(p, sample_queue_2);
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            case 7:{
                printf("===================\n");
                queue_print(sample_queue_2, 1, 0);
                printf("===================\n");
                break;
            }
            default:
                exit = 0;
                break;
        }
    }
    return 0;
}