/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 10:28:38
 * LastEditTime : 2022-02-06 12:11:18
 * Description  : [Weekly 279] | D
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumTime(char* s){
    int len = strlen(s);
    int cost = 0;
    //Deal with leftmost
    int l = 0;
    while(l < len && s[l] == '1'){
        cost++;
        l++;
    }
    //Deal with rightmost
    int r = len - 1;
    while(r > l && s[r] == '1'){
        cost++;
        r--;
    }
    //Justify middle
    int leftLen = r - l + 1;
    int* rmvFromLeft = (int*)malloc(sizeof(int) * leftLen);
    int* rmvFromRight = (int*)malloc(sizeof(int) * leftLen);
    int curMin = 0;
    //Traverse from left
    int i = 0;
    rmvFromLeft[i++] = 1;
    while(i < leftLen){
        rmvFromLeft[i] = rmvFromLeft[i - 1] + 1;
        if(s[l + i] == '1'){
            curMin += 2;
        }
        i++;
    }
    //Traverse from right
    i = leftLen - 1;
    rmvFromRight[i--] = 1;
    while(i >= 0){
        rmvFromRight[i] = rmvFromRight[i + 1] + 1;
        i--;
    }
    //Find solution
    int rmvCenter = curMin;
    for(int lp = 0; lp <= leftLen; ){
        if(lp != 0 && s[l + lp - 1] == '1'){
            rmvCenter -= 2;
        }
        int curCenter = rmvCenter;
        for(int rp = 0; rp <= leftLen - lp;){
            if(rp != 0 && s[r - rp + 1] == '1'){
                curCenter -= 2;
            }
            int curCost = curCenter;
            if(lp > 0){
                curCost += rmvFromLeft[lp - 1];
            }
            if(rp > 0){
                curCost += rmvFromRight[leftLen - rp];
            }
            curMin = curCost < curMin ? curCost : curMin;
            do{
                rp++;
            }while(rp <= leftLen - lp && s[r - rp + 1] != '1');
        }
        do{
            lp++;
        }while(lp <= leftLen && s[l + lp - 1] != '1');
    }
    cost += curMin;
    return cost;
}

int main(){
    char input[100000];
    scanf("%s", input);
    printf("%d\n", minimumTime(input));
    return 0;
}
