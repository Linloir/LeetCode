/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 10:28:33
 * LastEditTime : 2022-02-06 12:30:50
 * Description  : [Weekly 279] | B
 */

//Time out

#include <stdio.h>
#include <stdlib.h>

long long smallestNumber(long long num){
    int flag[10] = {0};
    int isPositive = num > 0;
    num = num > 0 ? num : -num;
    while(num){
        flag[num % 10]++;
        num /= 10;
    }
    if(isPositive){
        long long res = 0;
        //Chose from the smallest
        //find the first non-zero
        for(int i = 1; i < 10; i++){
            if(flag[i]){
                res += i;
                flag[i]--;
                break;
            }
        }
        //Input other numbers
        for(int i = 0; i < 10; i++){
            while(flag[i]){
                res *= 10;
                res += i;
                flag[i]--;
            }
        }
        return res;
    }
    else{
        long long res = 0;
        //Choose from the largest
        for(int i = 9; i >= 0; i--){
            while(flag[i]){
                res *= 10;
                res += i;
                flag[i]--;
            }
        }
        return -res;
    }
}