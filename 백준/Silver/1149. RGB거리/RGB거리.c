#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n, i, j;
	int min, lmin;
	int arr[2000][3];
	min = 10000000;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (i = 1; i < n; i++) {
		for (j = 0; j < 3; j++) {
			lmin = min;
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				else if (lmin > arr[i - 1][k]) {
					lmin = arr[i - 1][k];
				}
			}
			arr[i][j] += lmin;
		}
	}

	for (i = 0; i < 3; i++) {
		if (min > arr[n - 1][i])
			min = arr[n - 1][i];
	}

	printf("%d", min);
}