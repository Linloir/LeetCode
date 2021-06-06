/*
Jonathan Zhang (Linloir) @ 2021-6-6
*/

#ifndef _C_AVL_TREE_
#define _C_AVL_TREE_

typedef struct AVL_Tree AVL_Tree;
typedef struct AVL_Tree Node;
typedef struct AVL_Tree *PtrToNode;
typedef struct AVL_Tree *Tree;

struct AVL_Tree{
    int value;
    int height;
    PtrToNode l_child;
    PtrToNode r_child;
};

Tree tree_create();
Tree tree_make_empty(Tree);     //Empty a tree and return NULL
PtrToNode tree_find(Tree, int); //Find a value in the tree and return its pos
int tree_height(PtrToNode);     //Get the height of a node
PtrToNode tree_insert(Tree, int);       //Insert a value into the tree
PtrToNode tree_delete(Tree, int);       //Delete a value from the tree
PtrToNode tree_find_smaller_max(PtrToNode);     //Find and return the position of the max smaller value
PtrToNode tree_R_rotate(Tree, PtrToNode);       //R Rotate a tree around a node
PtrToNode tree_L_rotate(Tree, PtrToNode);       //L Rotate a tree around a node
PtrToNode tree_R_double_rotate(Tree, PtrToNode);    //R Double rotate a tree around a node
PtrToNode tree_L_double_rotate(Tree, PtrToNode);    //L Double rotate a tree around a node
void tree_print(Tree, int type, int level);        //Print a tree (CSDN:@jklinux)

#endif