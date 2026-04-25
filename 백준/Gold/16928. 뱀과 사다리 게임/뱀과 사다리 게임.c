#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int x;
} Queue;

Queue q[100 + 1];
int visited[101];
int l[31][2];
int front, rear;
int d, b;
int nx, x = 1;

void bfs() {
	int idx;

	while (front != rear) {
		x = q[front].x;
		
		for (int i = 6; i > 0; i--) {
			nx = i + x;
			idx = 0;
			b = 0;
			while (l[idx][0]) {
				if (l[idx][0] == nx) {
					nx = l[idx][1];
					d = visited[q[front].x];
					if (visited[nx] == 0) {
						q[rear].x = nx;
						rear++;
						visited[nx] = d+1;
					}
					b = 1;
					break;
				}
				idx++;
			}
			if (b == 1)
				continue;
			d = visited[q[front].x];
			if (visited[nx] == 0 && nx <= 100) {
				q[rear].x = nx;
				rear++;
				visited[nx] = d + 1;
			}
		}
		front++;
	}
}
int main() {
	int n, m;
	int i, a;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n + m; i++) {
		scanf("%d %d", &d, &a);
		l[i][0] = d;
		l[i][1] = a;
	}

	q[rear].x = 1;
	rear++;
	bfs();
	printf("%d", visited[100]);
}

