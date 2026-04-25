#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, ttotal, ftotal, i, j;
	scanf("%d", &n);
	ttotal = 0;
	ftotal = 0;
	for (j = 1; j <= n; j++) {
		i = j;
		while (i % 2 == 0) {
			ttotal++;
			i /= 2;
		}
		while (i % 5 == 0) {
			ftotal++;
			i /= 5;
		}
	}
	if (ftotal < ttotal) {
		printf("%d", ftotal);
	}
	else {
		printf("%d", ttotal);
	}
}