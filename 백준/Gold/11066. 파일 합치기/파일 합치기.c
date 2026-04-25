#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int t, k;
int i, j, m;
int arr[501] = { 0, };
int sum[501] = { 0, };
int dp[501][501] = { 0, };
int num[501][501] = { 0, };
int a;

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}

		for (i = 1; i <= k; i++) {
			num[i][i] = i;
		}

		for (i = 2; i <= k; i++) {
			for (j = i-1; j > 0; j--) {
				dp[j][i] = 2e+9;
				for (m =num[j][i-1] ; m <= num[j+1][i]; m++) {
					a = dp[j][m] + dp[m + 1][i] + sum[i] - sum[j-1];
					if (a < dp[j][i])
						dp[j][i] = a, num[j][i]=m;
				}
			}
		}

		printf("%d\n", dp[1][k]);
	}

	return 0;
}
