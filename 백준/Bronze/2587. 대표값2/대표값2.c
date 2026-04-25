#include <stdio.h>

int main() {
	int arr[5] = {0, };
	int i, j, m, mid, temp;
	m = 0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		m += arr[i];
	}
	m /= 5;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	mid = arr[2];
	printf("%d\n%d", m, mid);
}