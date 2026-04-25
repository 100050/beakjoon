#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int y;
	int x;
} Queue;

Queue q[1000 * 1000 + 1];
int visited[1000][1000];
int front, rear;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int time, b, d;

void bfs(int n, int m) {
	int ny, nx;

	while (front != rear) {
		for (int i = 0; i < 4; i++) {
			d = visited[q[front].y][q[front].x];
			ny = q[front].y + dy[i];
			nx = q[front].x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (visited[ny][nx] == 0) {
					q[rear].y = ny;
					q[rear].x = nx;
					rear++;
					visited[ny][nx] = d + 1;
				}
			}
		}
		front++;
	}
}
int main() {
	int l, i, j;
	int n, m;

	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &visited[i][j]);
			if (visited[i][j] == 1) {
				q[rear].y = i;
				q[rear].x = j;
				rear++;
			}
		}
	}

	bfs(n, m);

	b = 0;
	time = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				b = 1;
				time = -1;
				break;
			}
			else if (visited[i][j] > time + 1) {
				time = visited[i][j] - 1;
			}
		}
		if (b == 1)
			break;
	}


	printf("%d", time);

	return 0;
}

