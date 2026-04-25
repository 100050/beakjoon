#include <stdio.h>
#include <stdlib.h>

int graph[50][50] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;

void dfs(int y, int x) {
	int i;
	int ny, nx;

	for (i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (0 > nx || nx >= m || 0 > ny || ny >= n)
			continue;

		if (graph[ny][nx] == 1) {
			graph[ny][nx] = 0;
			dfs(ny, nx);
		}
	}
}

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main() {
	int i, j;
	int k, x, y, t, cnt;

	scanf("%d", &t);

	while (t--) {
		cnt = 0;

		scanf("%d %d %d", &m, &n, &k);
		for (i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			graph[y][x] = 1;
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (graph[i][j] == 0) {
					continue;
				}

				cnt++;
				graph[i][j] = 0;
				dfs(i, j);
			}
		}

		printf("%d\n", cnt);
	}
	
	return 0;
}
