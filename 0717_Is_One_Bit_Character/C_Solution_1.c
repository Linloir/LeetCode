/*** 
 * Author       : Linloir
 * Date         : 2022-02-20 10:20:57
 * LastEditTime : 2022-02-20 10:27:22
 * Description  : [20/2/2022 daily] | LeetCode 717 | Easy | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize){
    int i = 0;
    while(i < bitsSize - 1){
        if(bits[i] == 1){
            i += 2;
        }
        else{
            i += 1;
        }
    }
    return i == bitsSize - 1 && bits[i] == 0;
}
