#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* FindNext(struct Node* parent){
    while(parent && !parent->left && !parent->right){
        parent = parent->next;
    }
    return parent ? parent->left ? parent->left : parent->right : NULL;
}

struct Node* connect(struct Node* root){
    if(!root){
        return root;
    }
    if(!root->left && !root->right){
        return root;
    }
    if(root->next){
        if(root->right){
            root->right->next = FindNext(root);
            connect(root->right);
        }
        if(root->left){
            if(root->right){
                root->left->next = root->right;
            }
            else{
                root->left->next = FindNext(root);
            }
            connect(root->left);
        }
        return root;
    }
    if(root->right){
        connect(root->right);
    }
    if(root->left){
        if(root->right){
            root->left->next = root->right;
        }
        connect(root->left);
    }
    return root;
}