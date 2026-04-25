#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MOD 1000000007
typedef struct {
	long long val[2][2];
} Arr;

long long n;

Arr mul(Arr arr, long long b) {
	if (b == 1)
		return arr;
	else if (b % 2 == 1) {
		Arr res = mul(arr, b - 1);
		Arr res2 = { 0, };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long long temp = 0;
				for (int g = 0; g < 2; g++) {
					temp += res.val[i][g] * arr.val[g][j];
				}
				res2.val[i][j] = temp % MOD;
			}
		}
		return res2;
	}
	else {
		Arr res = mul(arr, b / 2);
		Arr res2 = { 0, };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long long temp = 0;
				for (int g = 0; g < 2; g++) {
					temp += res.val[i][g] * res.val[g][j];
				}
				res2.val[i][j] = temp % MOD;
			}
		}
		return res2;
	}
}

// A^5 = A^2 A^2 A
// A^5 A^2 A^1 
int main() {
	Arr arr;

	scanf("%lld", &n);
	arr.val[0][0] = 1;
	arr.val[1][0] = 1;
	arr.val[0][1] = 1;
	arr.val[1][1] = 0;

	Arr res = mul(arr, n);
	
	printf("%lld", res.val[1][0] % MOD);

	return 0;
}