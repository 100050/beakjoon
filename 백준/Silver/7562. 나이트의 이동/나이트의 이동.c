#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int y;
	int x;
} Queue;

Queue q[300 * 300 + 1];
int visited[300][300];
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int y, x;

void bfs(int py, int px, int I) {
	int ny, nx, d;
	int front, rear;

	front = 0; rear = 0;
	q[rear].y = py;
	q[rear].x = px;
	visited[py][px] = 0;

	while (q[front].y != y || q[front].x != x) {
		d = visited[q[front].y][q[front].x];

		for (int i = 0; i < 8; i++) {
			ny = q[front].y + dy[i];
			nx = q[front].x + dx[i];

			if (ny >= 0 && ny < I && nx >= 0 && nx < I) {
				if (!visited[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = d + 1;
				}
			}
		}
		front++;
	}
}
int main() {
	int t, l, i;
	int fy, fx;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &l);
		scanf("%d %d", &fy, &fx);
		scanf("%d %d", &y, &x);

		bfs(fy, fx, l);
		printf("%d\n", visited[y][x]);

		for (i = 0; i < l; i++)
			memset(visited[i], 0, sizeof(int) * l);
	}

	return 0;
}

