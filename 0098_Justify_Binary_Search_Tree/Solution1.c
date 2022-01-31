#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// WRONG-ANSWER
// int isValidBST(struct TreeNode* root){
//     int left = 1, right = 1;
//     if(!root->left && !root->right){
//         return 1;
//     }
//     if(root->left){
//         if(root->left->val < root->val){
//             left = isValidBST(root->left);
//         }
//         else{
//             left = 0;
//         }
//     }
//     if(root->right){
//         if(root->right->val > root->val){
//             right = isValidBST(root->right);
//         }
//         else{
//             right = 0;
//         }
//     }
//     return left && right;
// }

int VerifyNode(struct TreeNode* root, int* maximum, int* minimum){
    if(!root->left && !root->right){
        *maximum = root->val;
        *minimum = root->val;
        return 1;
    }
    int isLeftValid = 1, isRightValid = 1;
    *maximum = root->val;
    *minimum = root->val;
    if(root->left){
        int max, min;
        isLeftValid = VerifyNode(root->left, &max, &min);
        isLeftValid &= (max < root->val);
        *minimum = min; 
    }
    if(root->right){
        int max, min;
        isRightValid = VerifyNode(root->right, &max, &min);
        isRightValid &= (min > root->val);
        *maximum = max;
    }
    return isLeftValid && isRightValid;
}

int isValidBST(struct TreeNode* root){
    int max, min;
    int isLeftValid = 1, isRightValid = 1;
    if(root->left){
        isLeftValid = VerifyNode(root->left, &max, &min);
        isLeftValid &= (max < root->val);
    }
    if(root->right){
        isRightValid = VerifyNode(root->right, &max, &min);
        isRightValid &= (min > root->val);
    }
    return isLeftValid && isRightValid;
}