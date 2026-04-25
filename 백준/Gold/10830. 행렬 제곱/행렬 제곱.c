#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int val[5][5];
} Arr;

int n;

Arr mul(Arr arr, long long b) {
	if (b == 1)
		return arr;
	else if (b % 2 == 1) {
		Arr res = mul(arr, b - 1);
		Arr res2 = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = 0;
				for (int g = 0; g < n; g++) {
					temp += res.val[i][g] * arr.val[g][j];
				}
				res2.val[i][j] = temp % 1000;
			}
		}
		return res2;
	}
	else {
		Arr res = mul(arr, b / 2);
		Arr res2 = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = 0;
				for (int g = 0; g < n; g++) {
					temp += res.val[i][g] * res.val[g][j];
				}
				res2.val[i][j] = temp % 1000;
			}
		}
		return res2;
	}
}

// A^5 = A^2 A^2 A
// A^5 A^2 A^1 
int main() {
	int i, j;
	long long b;
	Arr arr = { 0, };
	scanf("%d %lld", &n, &b);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr.val[i][j]);
		}
	}
	Arr res = mul(arr, b);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", res.val[i][j] % 1000);
		}
		printf("\n");
	}

	return 0;
}