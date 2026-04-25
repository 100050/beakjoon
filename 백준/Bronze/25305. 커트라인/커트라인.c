#include <stdio.h> 

int main() {
	int arr[1000] = {0};
	int i, n, k, j, a;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				a = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = a;
			}
		}
	}
	for (i = n - 1; i > n - k; i--);
	printf("%d", arr[i]);
}