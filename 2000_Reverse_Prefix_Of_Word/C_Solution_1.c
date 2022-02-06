/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 10:20:34
 * LastEditTime : 2022-02-06 10:27:22
 * Description  : [2/2/2022 daily] | Leetcode 2000 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char* frag, int len){
    int i = 0;
    int j = len - 1;
    while(i < j){
        swap(&frag[i], &frag[j]);
        i++;
        j--;
    }
}

char* reversePrefix(char* word, char ch){
    int i = 0;
    while(word[i] != '\0'){
        if(word[i] == ch){
            break;
        }
        i++;
    }
    if(word[i] == ch){
        reverse(word, i + 1);
    }
    return word;
}

//TestBench
void TestBench(){
    char input[256];
    scanf("%s", input);
    getchar();
    char ch;
    scanf("%c", &ch);
    printf("%s\n", reversePrefix(input, ch));
}

int main(){
    TestBench();
    return 0;
}
