/*
Jonathan Zhang (Linloir) @ 2021-6-2
Time:   16ms
Memory: 5.9Mb
*/

#include <stdio.h>
#include <math.h>

bool isPalindrome(int x) {
    int tmp = x;
    if (x < 0)
        return false;
    else {
        int rev = 0;
        while (x != 0) {
            if (rev > 214748364)
                return false;
            else {
                rev = rev * 10 + x % 10;
                x = x / 10;
            }
        }
        return rev == tmp;
    }
}

int main() {
    int x = 1234567899;
    printf("%s", isPalindrome(x) ? "Yes" : "No");
    return 0;
}