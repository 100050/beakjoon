#include <stdio.h>

int main() {
	int f, s, i, a;
	int arr[31] = {0, };
	for (i = 0; i < 28; i++) {
		scanf("%d", &a);
		arr[a] = 1;
	}
	for (i = 1; i <= 30; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}
}