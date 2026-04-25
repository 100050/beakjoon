#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, i, res;

	scanf("%d", &n);


	res = 0;
	for (i = 1; i * i <= n; i++) {
		res++;
	}

	printf("%d", res);

	return 0;
}