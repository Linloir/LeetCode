/*
Jonathan Zhang (Linloir) @ 2021-6-6
*/

#include "c_avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree tree_create(){
    return NULL;
}

Tree tree_make_empty(Tree tree){
    if(tree != NULL){
        tree_make_empty(tree->l_child);
        tree_make_empty(tree->r_child);
        free(tree);
    }
    return NULL;
}

PtrToNode tree_find(Tree tree, int value){
    if(tree == NULL)
        return NULL;
    if(value = tree->value)
        return tree;
    else if(value < tree->value)
        return tree_find(tree->l_child, value);
    else
        return tree_find(tree->r_child, value);
}

int tree_height(PtrToNode node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}

PtrToNode tree_insert(Tree tree, int value){
    if(tree == NULL){
        //malloc new node
        tree = (Tree)malloc(sizeof(AVL_Tree));
        if(tree == NULL){
            printf("Not enough space.\n");
            return NULL;
        }

        //set value
        tree->l_child = NULL;
        tree->r_child = NULL;
        tree->value = value;
    }

    else if(value == tree->value){
        printf("Value is already in the tree.\n");
    }
    else if(value < tree->value){
        tree->l_child = tree_insert(tree->l_child, value);
        if(tree_height(tree->l_child) - tree_height(tree->r_child) == 2){
            if(value < tree->l_child->value){
                tree = tree_R_rotate(tree, tree->l_child);
            }
            else{
                tree = tree_R_double_rotate(tree, tree->l_child);
            }
        }
    }
    else{
        tree->r_child = tree_insert(tree->r_child, value);
        if(tree_height(tree->r_child) - tree_height(tree->l_child) == 2){
            if(value > tree->r_child->value){
                tree = tree_L_rotate(tree, tree->r_child);
            }
            else{
                tree = tree_L_double_rotate(tree, tree->r_child);
            }
        }
    }

    int l_height = tree_height(tree->l_child);
    int r_height = tree_height(tree->r_child);
    tree->height = l_height > r_height ? l_height + 1 : r_height + 1;

    return tree;
}

PtrToNode tree_delete(Tree tree, int value){
    if(tree == NULL){
        printf("Empty tree\n");
        return NULL;
    }
    if(value == tree->value){
        if(tree->l_child == NULL){
            PtrToNode r = tree->r_child;
            free(tree);
            tree = r;
        }
        else if(tree->r_child == NULL){
            PtrToNode l = tree->l_child;
            free(tree);
            tree = l;
        }
        else{
            PtrToNode sm_max = tree_find_smaller_max(tree);
            int sm_value = sm_max->value;
            tree = tree_delete(tree, sm_value);
            tree->value = sm_value;
            if(tree_height(tree->r_child) - tree_height(tree->l_child) == 2){
                if (tree_height(tree->r_child->r_child) >= tree_height(tree->r_child->l_child)){
                    tree = tree_L_rotate(tree, tree->r_child);
                }
                else{ 
                    tree = tree_L_double_rotate(tree, tree->r_child);
                }
            }
        }
    }
    else if(value < tree->value){
        tree->l_child = tree_delete(tree->l_child, value);
        if(tree_height(tree->r_child) - tree_height(tree->l_child) == 2){
            if(tree_height(tree->r_child->r_child) >= tree_height(tree->r_child->l_child)){
                tree = tree_L_rotate(tree, tree->r_child);
            }
            else{
                tree = tree_L_double_rotate(tree, tree->r_child);
            }
        }
    }
    else{
        tree->r_child = tree_delete(tree->r_child, value);
        if(tree_height(tree->l_child) - tree_height(tree->r_child) == 2){
            if(tree_height(tree->l_child->l_child) >= tree_height(tree->l_child->r_child)){
                tree = tree_R_rotate(tree, tree->l_child);
            }
            else{
                tree = tree_R_double_rotate(tree, tree->l_child);
            }
        }
    }

    if(tree != NULL){
        int l_height = tree_height(tree->l_child);
        int r_height = tree_height(tree->r_child);
        tree->height = l_height > r_height ? l_height + 1 : r_height + 1;
    }
    return tree;
}

PtrToNode tree_find_smaller_max(PtrToNode node){
    PtrToNode iterator = node->l_child;
    while(iterator->r_child != NULL){
        iterator = iterator->r_child;
    }
    return iterator;
}

PtrToNode tree_R_rotate(Tree tree, PtrToNode node){
    tree->l_child = node->r_child;
    node->r_child = tree;
    int height_l;
    int height_r;
    height_l = tree_height(node->l_child);
    height_r = tree_height(node->r_child);
    node->height = height_l > height_r ? height_l + 1 : height_r + 1;
    height_l = tree_height(tree->l_child);
    height_r = tree_height(tree->r_child);
    tree->height = height_l > height_r ? height_l + 1 : height_r + 1;
    return node;
}

PtrToNode tree_L_rotate(Tree tree, PtrToNode node){
    tree->r_child = node->l_child;
    node->l_child = tree;
    int height_l;
    int height_r;
    height_l = tree_height(node->l_child);
    height_r = tree_height(node->r_child);
    node->height = height_l > height_r ? height_l + 1 : height_r + 1;
    height_l = tree_height(tree->l_child);
    height_r = tree_height(tree->r_child);
    tree->height = height_l > height_r ? height_l + 1 : height_r + 1;
    return node;
}

PtrToNode tree_R_double_rotate(Tree tree, PtrToNode node){
    tree->l_child = tree_L_rotate(tree->l_child, tree->l_child->r_child);
    return tree_R_rotate(tree, node);
}

PtrToNode tree_L_double_rotate(Tree tree, PtrToNode node){
    tree->r_child = tree_R_rotate(tree->r_child, tree->r_child->l_child);
    return tree_L_rotate(tree, node);
}

void tree_print(PtrToNode n, int type,  int level)
{
	int i;

	if (NULL == n)
		return;

	tree_print(n->r_child, 2, level+1);
	switch (type)
	{
	case 0:
		printf("%2d\n", n->value);
		break;
	case 1:
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("\\ %2d\n", n->value);
		break;
	case 2:
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("/ %2d\n", n->value);
		break;	
	}
	tree_print(n->l_child, 1,  level+1);
}