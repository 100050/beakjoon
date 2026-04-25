#include <stdio.h>
#include <stdlib.h>

int main() {
	long long a, b, c, d, t, n, i;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n <= 3) {
			printf("1\n");
			continue;
		}
		a = 1; b = 1; c = 1; d = 0;
		for (i = 3; i < n; i++) {
			d = a + b;
			a = b;
			b = c;
			c = d;
		}
		printf("%lld\n", d);
	}
}