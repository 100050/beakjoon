#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memory[101];
int cost[101];
int dp[10001];

int main() {
	int n, m;
	int i, j;
	int min = 100 * 100;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &memory[i]);
	}

	for (i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);

	}

	for (i = 1; i <= n; i++) {
		for (j = 100*n; j >= 0; j--) {
			if (j >= cost[i]) {
				dp[j] =
					dp[j] > dp[j - cost[i]] + memory[i] ?
					dp[j] :
					dp[j - cost[i]] + memory[i];
			}
			else {
				dp[j] = dp[j];
			}

			if (dp[j] >= m && min > j) {
				min = j;
			}
		}
	}

	printf("%d", min);
}