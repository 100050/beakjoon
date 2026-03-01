#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[1000];
	int n, k, i, j, g;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	j = 0;
	printf("<");
	for (i = 0; i < n; i++) {
		for (g = 0; g < k; g++) {
			j++;
			if (j > n) {
				j = 1;
			}
			if (arr[j - 1] == -1) {
				g--;
			}
		}
		if (arr[j - 1] != -1) {
			if (i == n - 1) {
				printf("%d", arr[j - 1]);
			}
			else {
				printf("%d, ", arr[j - 1]);
			}
			arr[j - 1] = -1;
		}
		else {
			i--;
		}
	}
	printf(">");
}