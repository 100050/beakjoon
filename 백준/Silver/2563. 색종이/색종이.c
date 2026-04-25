#include <stdio.h>

int main() {
	char arr[101][101] = {0, };
	int n, i, j, k, a, b, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (j = a; j < a + 10; j++) {
			for (k = b; k < b + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}
	t = 0;
	for (j = 1; j < 101; j++) {
		for (k = 1; k < 101; k++) {
			if (arr[j][k] == 1) {
				t++;
			}
		}
	}
	printf("%d", t);
}