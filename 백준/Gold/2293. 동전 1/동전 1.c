#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[101];

int main() {
	int* r = (int*)calloc(10001, sizeof(int));
	int* l = (int*)calloc(10001, sizeof(int));
	int* temp;
	int n, k;
	int i, j;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	// i-k
	/*
	0 1 2 5
	1 1 1 1
	2 1 2 2
	3 1 2 2
	4 1 3 3
	5 1 3 4
	6 1 4 5
	7 1 4 6
	8 1 5 8
	9 1 5 8
	10 1 6 10
	dp[i][j-1] + dp[i-arr[j]][j]
	dp[i][j] = dp[i-arr[j]][j] + i % arr[i]
	*/

	for (j = 1; j <= n; j++) {
		for (i = 1; i <= k; i++) {
			if (i <= arr[j]) {
				r[i] = l[i] + i / arr[j];
				continue;
			}
			r[i] = l[i] + r[i - arr[j]];
		}
		temp = r;
		r = l;
		l = temp;
	}

	printf("%d", l[k]);

	free(r);
	free(l);
}
