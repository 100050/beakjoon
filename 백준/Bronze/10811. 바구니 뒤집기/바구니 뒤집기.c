#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int i, j, temp;
	int* arr;
	int a, b, c;
	
	scanf("%d %d", &n, &m);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 1; i <= n; i++) {
		arr[i-1] = i;
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);

		if ((b - a) % 2 == 1) {
			c = (b - a) / 2 + 1;
		}
		else {
			c = (b - a) / 2;
		}
		j = 0;
		while (c--) {
			temp = arr[b - 1 - j];
			arr[b - 1 - j] = arr[a - 1 + j];
			arr[a - 1 + j] = temp;
			j++;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}