/*
Jonathan Zhang (Linloir) @ 2021-6-2
time:	
memory:	
*/

#include <stdio.h>

//leetcode version
int reverse(int x) {
	
	int rev = 0;
	while (x != 0) {
		if (rev < -_CRT_INT_MAX / 10 || rev > _CRT_INT_MAX / 10) {
			return 0;
		}
		int digit = x % 10;
		x /= 10;
		rev = rev * 10 + digit;
	}
	return rev;
}

int main() {
	int x = 1534236461;
	int result = reverse(x);
	printf("%d", result);
	return 0;
}

//Thinking:
//Using math calculation instead of complex arithmetic is a good solution.

/*
bad version 1 overflow

int reverse(int x) {
	int sym = x > 0 ? 1 : -1;
	unsigned char digit[10];
	int n = 0;
	x = x > 0 ? x : -x;
	do {
		digit[n] = x % 10;
		x = x / 10;
		n++;
	} while (x > 0);
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result * 10 + digit[i];
	}
	return result > 4294967296 ? 0 : sym * result;
}

int main() {
	int x = 1534236469;
	int result = reverse(x);
	printf("%d", result);
	return 0;
}
*/