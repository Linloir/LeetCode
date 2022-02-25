/*** 
 * Author       : Linloir
 * Date         : 2022-02-25 22:53:29
 * LastEditTime : 2022-02-25 23:00:37
 * Description  : [25/2/2022 daily] | LeetCode 537 | Medium | C Solution 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* complexNumberMultiply(char* num1, char* num2){
    int real1, real2, imag1, imag2;
    sscanf(num1, "%d+%di", &real1, &imag1);
    sscanf(num2, "%d+%di", &real2, &imag2);
    int newReal = real1 * real2 - imag1 * imag2;
    int newImag = real1 * imag2 + real2 * imag1;
    char* res = (char*)malloc(sizeof(char) * (strlen(num1) + strlen(num2)));
    memset(res, 0, sizeof(char) * (strlen(num1) + strlen(num2)));
    sprintf(res, "%d+%di", newReal, newImag);
    return res;
}
