#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	char y;
	char x;
	char z;
} Queue;

Queue q[100 * 100 * 100 + 1];
int visited[100][100][100];
int front, rear;
char dy[6] = { -1, 0, 1, 0, 0, 0 };
char dx[6] = { 0, 1, 0, -1, 0, 0 };
char dz[6] = { 0, 0, 0, 0, 1, -1 };
int time, b, d;

int main() {
	int l, i, j, k;
	int n, m, h;

	scanf("%d %d %d", &m, &n, &h);

	for (k = 0; k < h; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &visited[k][i][j]);
				if (visited[k][i][j] == 1) {
					q[rear].y = i;
					q[rear].x = j;
					q[rear].z = k;
					rear++;
				}
			}
		}
	}
int ny, nx, nz;

while (front != rear) {
	for (int i = 0; i < 6; i++) {
		d = visited[q[front].z][q[front].y][q[front].x];
		ny = q[front].y + dy[i];
		nx = q[front].x + dx[i];
		nz = q[front].z + dz[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && nz >= 0 && nz < h) {
			if (visited[nz][ny][nx] == 0) {
				q[rear].y = ny;
				q[rear].x = nx;
				q[rear].z = nz;
				rear++;
				visited[nz][ny][nx] = d + 1;
			}
		}
	}
	front++;
}

	b = 0;
	time = 0;
	for (k = 0; k < h; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (visited[k][i][j] == 0) {
					b = 1;
					time = -1;
					break;
				}
				else if (visited[k][i][j] > time + 1) {
					time = visited[k][i][j] - 1;
				}
			}
			if (b == 1)
				break;
		}
		if (b == 1)
			break;
	}


	printf("%d", time);

	return 0;
}

