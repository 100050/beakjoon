#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n, k, i;
	int l, r, m, t;

	scanf("%d %d", &n, &k);
	
	l = 1;
	r = k;
	while (l < r) {
		t = 0;
		m = (l + r) / 2;


		for (i = 1; i <= n; i++) {
			if (n > m/ i) {
				t += m / i;
			}
			else {
				t += n;
			}
		}

		if (t < k) {
			l = m + 1;
		}
		else if (t >= k) {
			r = m;
		}
	}
	printf("%d", l);

	return 0;
}