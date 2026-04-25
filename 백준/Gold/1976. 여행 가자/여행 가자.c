#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[201];
int graph[201][201];

int Find(int temp) {
	if (arr[temp] == temp)
		return temp;
	else
		return arr[temp] = Find(arr[temp]);
}

void Union(int x, int y) {
	int nx, ny;

	nx = Find(x);
	ny = Find(y);

	if (nx != ny) {
		arr[nx] = ny;
	}
}

int main() {
	int n, m, a, b;
	int i, j, x, y;

	scanf("%d\n%d", &n, &m);
	for (i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j]) {
				Union(i, j);
			}
		}
	}
	scanf("%d", &a);
	a = Find(a);
	for (i = 1; i < m; i++) {
		scanf("%d", &b);
		b = Find(b);
		if (a != b) {
			break;
		}
		
	}
	if (i != m) {
		printf("NO");
	}
	else {
		printf("YES");
	}

	return 0;
}
