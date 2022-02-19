/*** 
 * Author       : Linloir
 * Date         : 2022-02-18 20:58:24
 * LastEditTime : 2022-02-18 21:35:46
 * Description  : [18/2/2022 daily] | LeetCode 1791 | Easy | C Solution 2
 */

#include <stdio.h>
#include <stdlib.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize){
    return edges[0][0] == edges[1][0] ? edges[0][0] : edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
}