#include <stdio.h>
#include <stdlib.h>

int graph[25][25] = { 0, };
int result[(25 * 25 + 1) / 2] = { 0, };
int cnt = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n;

void dfs(int y, int x) {
	int i;
	int ny, nx;

	for (i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (0 > nx || nx >= n || 0 > ny || ny >= n)
			continue;

		if (graph[ny][nx] == 1) {
			result[cnt]++;
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

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (graph[i][j] == 0) {
				continue;
			}
			result[cnt]++;
			graph[i][j] = 0;
			dfs(i, j);
			if (result[cnt] != 0) {
				cnt++;
			}
		}
	}

	qsort(result, cnt, sizeof(int), compare);

	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}