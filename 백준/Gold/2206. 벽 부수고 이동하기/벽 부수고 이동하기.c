#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long

int arr[1000][1000];
int visited[1000][1000][2] = { 0, };
int n, m;

typedef struct {
	int x;
	int y;
	int wall;
	int res;
} c;

c queue[1000*1000*2 + 1];
int top = -1;
int bottom = -1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs() {
	int i, j;
	int res = 0;

	++top;
	++bottom;
	queue[top].x = 0;
	queue[top].y = 0;
	queue[top].res = 0;
	queue[top].wall = 1;
	visited[0][0][0] = 1;
	//printf("33\n");
	while (top >= bottom) {
		int x = queue[bottom].x;
		int y = queue[bottom].y;
		int wall = queue[bottom].wall;
		int res = queue[bottom].res;
		bottom++;
		
		if (x == m - 1 && y == n - 1) {
		//	printf("48 %d %d\n", top, bottom);
			return res;
		}

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= m || 0 > ny || ny >= n)
				continue;
			
			if (visited[ny][nx][!wall]) {
				continue;
			}
			/*
			
			00000
			01111
			00000
			11110
			00000
			01111
			00010
			
			*/
			if (arr[ny][nx] && wall) {
				++top;
				queue[top].x = nx;
				queue[top].y = ny;
				queue[top].wall = 0;
				queue[top].res = res + 1;


				visited[ny][nx][1] = 1;
			}

			if (!arr[ny][nx]) {
				++top;
				queue[top].x = nx;
				queue[top].y = ny;
				queue[top].res = res + 1;
				queue[top].wall = wall;

				visited[ny][nx][!wall] = 1;
			}
		}
		//if (wall)
			//printf("%d %d %d %d\n", y, x, res, wall);

	}
	//printf("exit");

	return -2;
}

void solve() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	printf("%d", bfs() + 1);
}

int main() {
	
	solve();

	return 0;
}