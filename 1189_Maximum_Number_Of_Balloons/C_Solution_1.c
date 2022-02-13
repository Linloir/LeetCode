/*** 
 * Author       : Linloir
 * Date         : 2022-02-13 10:13:38
 * LastEditTime : 2022-02-13 10:29:19
 * Description  : [13/2/2022 daily] | LeetCode 1189 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>

int ID(char c){
    switch (c)
    {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'l':
        return 2;
    case 'n':
        return 3;
    case 'o':
        return 4;
    default:
        return 5;
    }
}

int maxNumberOfBalloons(char* text){
    int freq[6] = {0};
    for(int i = 0; text[i] != '\0'; i++){
        freq[ID(text[i])]++;
    }
    freq[2] /= 2;
    freq[4] /= 2;
    int min = freq[0];
    for(int i = 1; i < 5; i++){
        min = freq[i] < min ? freq[i] : min;
    }
    return min;
}
