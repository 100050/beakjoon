#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int c[30];
int g[7];
int dp[30001][31];
int n, m;

void dfs(int d, int sum) {
	if (d == n+1)
		return;

	if (dp[sum+15000][d] != 0)
		return;

	dp[sum+15000][d] = 1;

	dfs(d + 1, sum + c[d]);
	dfs(d + 1, sum);
	dfs(d + 1, sum - c[d]);
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &g[i]);
	}


	dfs(0, 0);

	for (i = 0; i < m; i++) {
        if (g[i] > 15000) {
            printf("N ");
            continue;
        }
		printf(dp[g[i]+15000][n] ? "Y " : "N ");
	}
}