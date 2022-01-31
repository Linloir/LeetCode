/*
Jonathan Zhang (Linloir) @ 2021-6-6
*/

#include <stdio.h>
#include "c_avl_tree.h"

int main(){
    printf("Test AVL Tree:\n");
    printf("Commands:\n");
    printf("[0] exit\n");
    printf("[1] insert value into the tree\n");
    printf("[2] delete value from the tree\n");

    Tree sample_tree = tree_create();
    tree_print(sample_tree, 0, 0);

    int exit = 1;
    while(exit){
        int command = -1;
        
        scanf("%d", &command);
        if(command == 0){
            exit = 0;
            continue;
        }
        else if(command == 1){
            int value;
            scanf("%d", &value);
            sample_tree = tree_insert(sample_tree, value);
            tree_print(sample_tree, 0, 0);
            printf("\n");
        }
        else if(command == 2){
            int value;
            scanf("%d", &value);
            sample_tree = tree_delete(sample_tree, value);
            tree_print(sample_tree, 0, 0);
            printf("\n");
        }
    }
    return 0;
}