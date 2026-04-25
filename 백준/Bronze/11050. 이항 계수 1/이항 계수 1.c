#include <stdio.h>

int main() {
	int n, k, i, j, t;
	scanf("%d %d", &n, &k);
	t = 1;
	for (i = 0; i < k; i++) {
		t *= n - i;
	}
	for (i = 0; i < k; i++) {
		t /= i + 1;
	}
	printf("%d", t);
}