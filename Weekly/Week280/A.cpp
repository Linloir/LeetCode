/*** 
 * Author       : Linloir
 * Date         : 2022-02-13 10:29:38
 * LastEditTime : 2022-02-13 12:19:04
 * Description  : [Weekly 280] | A
 */

#include <stdio.h>
#include <stdlib.h>

int countOperations(int num1, int num2){
    int count = 0;
    while(num1 && num2){
        if(num1 >= num2){
            num1 -= num2;
        }
        else{
            num2 -= num1;
        }
        count++;
    }
    return count;
}

int main(){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d", countOperations(num1, num2));
    return 0;
}
