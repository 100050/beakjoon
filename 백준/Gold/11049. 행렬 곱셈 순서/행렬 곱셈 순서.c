#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int nm[501][2];
int dp[501][501];

int main() {
	int n, i, j;
	int a;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &nm[i][0], &nm[i][1]);
	}

	for (i = 2; i <= n; i++) {
		for (j = i - 1; j > 0; j--) {
			dp[j][i] = 2e+9;
			for (int m = j; m < i; m++) {
				a = dp[j][m] + dp[m + 1][i] + nm[j][0]*nm[m][1]*nm[i][1];

				if (a < dp[j][i]) {
					dp[j][i] = a;
				}
			}
		}
	}

	printf("%d", dp[1][n]);
}
