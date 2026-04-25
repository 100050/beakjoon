#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[1000000];
int nge[1000000];
int stack[1000000][2];

int main() {
	int i, j;
	int n, val;
	int bottom = 0, top = 0, idx = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	i = 0;
	stack[top][1] = i;
	stack[top++][0] = arr[i++];
	while(top != 0 && i < n) {
		stack[top][1] = i;
		stack[top++][0] = arr[i++];
		if (stack[top - 1][0] > stack[top - 2][0]) {
			val = stack[top - 1][0];
			idx = stack[top - 1][1];
			while (top - 2 >= 0 && val > stack[top - 2][0]) {
				nge[stack[top - 2][1]] = val;
				top--;
			}
			stack[top-1][1] = idx;
			stack[top-1][0] = val;
		}
	}

	for (i = 0; i < n; i++) {
		if (nge[i] == 0)
			printf("-1 ");
		else
			printf("%d ", nge[i]);
	}
}