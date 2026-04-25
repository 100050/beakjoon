#include <stdio.h> 

int main() {
	int arr[10000] = {0, };
	int i, n, x, j;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x - 1]++;
	}
	for (i = 0; i < 10000; i++) {
		if (arr[i] != 0) {
			for (j = 0; j < arr[i]; j++) {
				printf("%d\n", i+1);
			}
		}
	}
}