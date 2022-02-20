/*** 
 * Author       : Linloir
 * Date         : 2022-02-20 10:29:16
 * LastEditTime : 2022-02-20 10:38:38
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int n){
    int orig = n;
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum % 2 == 0;
}

int countEven(int num){
    int count = 0;
    for(int i = 1; i <= num; i++){
        if(isValid(i)){
            count++;
        }
    }
    return count;
}

void TestBench(){
    int num;
    scanf("%d", &num);
    printf("%d\n", countEven(num));
}

int main(){
    TestBench();
    return 0;
}