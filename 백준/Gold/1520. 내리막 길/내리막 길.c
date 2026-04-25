#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int graph[501][501];
int dp[501][501];
char visit[501][501];
int vy[4] = { 0, 1, 0, -1 };
int vx[4] = { 1, 0, -1, 0 };
int idx;
int n, m;

int dfs(int y, int x) {
	int nx, ny;
	int ways = 0;

	if (x == 1 && y == 1) {
		return 1;
	}
	if (visit[y][x] == 1) {
		return dp[y][x];
	}

	for (int i = 0; i < 4; i++) {
		nx = x + vx[i];
		ny = y + vy[i];
		
		if (nx > m || nx < 1 || ny > n || ny < 1)
			continue;

		if (graph[ny][nx] > graph[y][x]) {
			ways += dfs(ny, nx);
			visit[ny][nx] = 1;
		}
	}
	dp[y][x] += ways;

	return dp[y][x];
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	dfs(n, m);

	printf("%d", dp[n][m]);

}
