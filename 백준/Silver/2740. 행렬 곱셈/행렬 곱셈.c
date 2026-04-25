#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[100][100][3] = { 0, };
int main() {
	int n, m, k;
	int i, j, g;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j][0]);
		}
	}
	scanf("%d %d", &m, &k);
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++) {
			scanf("%d", &arr[i][j][1]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			for (g = 0; g < m; g++) {
				arr[i][j][2] += arr[i][g][0] * arr[g][j][1];
			}
			printf("%d ", arr[i][j][2]);
		}
		printf("\n");
	}

}