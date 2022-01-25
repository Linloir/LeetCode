#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashMap* Map;
typedef struct listNode Node;
typedef Node* List;

struct hashMap{
    int size;
    List* headList;
};

struct listNode{
    char val;
    int freq;
    List next;
};

Map CreateMap(int size){
    Map newMap = (Map)malloc(sizeof(struct hashMap));
    newMap->size = size;
    newMap->headList = (List*)malloc(sizeof(List) * size);
    for(int i = 0; i < size; i++){
        //create dummy head
        newMap->headList[i] = (List)malloc(sizeof(struct listNode));
        newMap->headList[i]->val = 0;
        newMap->headList[i]->freq = 0;
        newMap->headList[i]->next = NULL;
    }
    return newMap;
}

void DestroyList(List list){
    if(list == NULL)
        return;
    DestroyList(list->next);
    free(list);
}

void DestroyMap(Map map){
    for(int i = 0; i < map->size; i++){
        DestroyList(map->headList[i]);
    }
    free(map->headList);
    free(map);
}

int hashAddr(int size, char c){
    //get the hashAddr of char c
    return (int)c % size;
}

void ListInsert(List head, char c){
    //head refers to the dummy head
    List ptr = head->next;
    while(ptr != NULL){
        if(ptr->val == c){
            ptr->freq++;
            return;
        }
        else
            ptr = ptr->next;
    }
    ptr = (List)malloc(sizeof(struct listNode));
    ptr->val = c;
    ptr->freq = 1;
    ptr->next = head->next;
    head->next = ptr;
    return;
}

void MapInsert(Map map, char c){
    int addr = hashAddr(map->size, c);
    ListInsert(map->headList[addr], c);
}

int longestPalindrome(char * s){
    Map dic = CreateMap(10);
    for(int i = 0; i < strlen(s); i++)
        MapInsert(dic, s[i]);
    int ans = 0;
    int curLongestOdd = 0;
    for(int i = 0; i < dic->size; i++){
        List ptr = dic->headList[i]->next;
        while(ptr != NULL){
        printf("curLongest:%d\n", curLongestOdd);
            if(ptr->freq & 1){
                //odd
                if(ptr->freq > curLongestOdd){
                    if(curLongestOdd != 0)
                        ans--;
                    curLongestOdd = ptr->freq;
                    ans += curLongestOdd;
                }
                else
                    ans += ptr->freq - 1;
            }
            else
                ans += ptr->freq;
            ptr = ptr->next;
        }
    }
    DestroyMap(dic);
    return ans;
}

int main(){
    char s[1024];
    scanf("%s", s);
    int ans = longestPalindrome(s);
    printf("%d", ans);
    return 0;
}