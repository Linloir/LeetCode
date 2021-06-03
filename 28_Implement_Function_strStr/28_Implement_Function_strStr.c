/*
Jonathan Zhang (Linloir) @ 2021-6-3
Time:   0ms
Memory: 5.8Mb
*/

#include <stdio.h>

int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0)
        return 0;
    int len_1 = strlen(haystack);
    int len_2 = strlen(needle);
    if(len_1 < len_2)
        return -1;
    int ptr_1 = 0;
    int ptr_2 = 0;
    for (; ptr_1 < len_1 - len_2 + 1;){
        while(ptr_2 < len_2 && haystack[ptr_1++] == needle[ptr_2]){
            ptr_2++;
        }
        if(ptr_2 == len_2)
            return ptr_1 - len_2;
        ptr_1 = ptr_1 - (ptr_2 == 0 ? 0: ptr_2);
        ptr_2 = 0;
    }
    return -1;
}

/*
After Solution:
易错点：在诸如mississippi中的两个ssi可能会导致函数失效，结尾的ppi中的两个p可能导致变量溢出，这些都是要考虑的问题
*/

int main(){
    char haystack[] = "mississippi";
    char needle[] = "pi";
    int p = strStr(haystack, needle);
    printf("%d\n", p);
    return 0;
}