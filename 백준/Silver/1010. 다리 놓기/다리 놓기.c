#include <stdio.h>

int main() {
	unsigned long long n, k, i, r, j, t;
	scanf("%llu", &t);
	for (i = 0; i < t; i++) {
		r = 1;
		scanf("%llu %llu", &k, &n);
		for (j = 0; j < k; j++) {
			r *= n - j;
			r /= j + 1;
		}
		printf("%llu\n", r);
	}
}