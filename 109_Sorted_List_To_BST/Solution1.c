#include <stdio.h>
#include <stdlib.h>
#include "../TestBench/common_tree.h"
#include "../TestBench/linked_list.h"

struct TreeNode* buildBST(int* array, int size){
    if(size <= 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = buildBST(array, size / 2);
    root->right = buildBST(array + size / 2 + 1, (size + 1) / 2 - 1);
    root->val = array[size / 2];
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int listSize = 10;
    int* list = (int*)malloc(sizeof(list) * listSize);
    int listLength = 0;
    struct ListNode* iter = head->next;
    //struct ListNode* iter = head;
    while(iter){
        list[listLength++] = iter->val;
        if(listLength == listSize){
            listSize *= 2;
            list = (int*)realloc(list, sizeof(int) * listSize);
        }
        iter = iter->next;
    }
    if(listLength == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = list[listLength / 2];
    root->left = buildBST(list, listLength / 2);
    if(listLength > 2){
        root->right = buildBST(&list[listLength / 2 + 1], (listLength + 1) / 2 - 1);
    }
    else{
        root->right = NULL;
    }
    return root;
}

//TestBench
void TestBench(){
    List sortedList = GenerateList(From_Input, 0, 0);
    PrintList(sortedList);
    Tree res = sortedListToBST(sortedList);
    PrintTree(res);
    // List sortedList = GenerateList(From_Random_Generator, 50, 100);
    // SortList(sortedList);
    // PrintList(sortedList);
    // Tree res = sortedListToBST(sortedList);
    // PrintTree(res);
}

int main(){
    TestBench();
    return 0;
}