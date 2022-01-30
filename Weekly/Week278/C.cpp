#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long quickpowmod(int base, int power, int modulo){
    long long res = 1 % modulo;
    long long cur = base % modulo;
    int k = power;
    while(k > 0){
        if(k & 1){
            res = res * cur % modulo;
        }
        cur = cur * cur % modulo;
        k >>= 1;
    }
    return res;
}

char* subStrHash(char* s, int power, int modulo, int k, int hashValue){
    int len = strlen(s);
    int* valmap = (int*)malloc(sizeof(int) * len);
    long long* powmap = (long long*)malloc(sizeof(long long) * (k + 1));
    for(int i = 0; i < len; i++){
        valmap[i] = (s[i] - 'a' + 1);
    }
    for(int i = 0; i <= k; i++){
        powmap[i] = quickpowmod(power, i, modulo);
    }
    for(int strt = 0; strt < len; strt++){
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += (valmap[strt + i] * powmap[i]) % modulo;
        }
        sum %= modulo;
        if(sum == hashValue){
            char* res = (char*)malloc(sizeof(char) * (k + 1));
            for(int i = 0; i < k; i++){
                res[i] = s[strt + i];
            }
            res[k] = '\0';
            return res;
        }
    }
    return NULL;
}

int main(){
    char input[256] = {0};
    int p, m, k, h;
    scanf("%s", input);
    scanf("%d%d%d%d", &p, &m, &k, &h);
    char* res = subStrHash(input, p, m, k, h);
    printf("%s\n", res);
    return 0;
}