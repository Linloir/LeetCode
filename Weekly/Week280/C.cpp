/*** 
 * Author       : Linloir
 * Date         : 2022-02-13 11:15:26
 * LastEditTime : 2022-02-13 12:19:01
 * Description  : [Weekly 280] | C
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return (*(int*)b - *(int*)a);
}

long long minimumRemoval(int* beans, int beansSize){
    qsort(beans, beansSize, sizeof(int), cmp);
    long long sum = 0;
    for(int i = 0; i < beansSize; i++){
        sum += beans[i];
    }
    long long prev = beans[0];
    sum -= beans[0];
    long long mult = 1;
    long long count = 0;
    int i = 1;
    int j = 0;
    while(i < beansSize){
        long long cur = beans[i];
        if((prev - cur) * mult >= sum){
            return count + sum;
        }
        else{
            count += (prev - cur) * mult;
            mult++;
            prev = cur;
        }
        sum -= cur;
        i++;
    }
    return count;
}

