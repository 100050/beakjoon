#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char arr[1000001];

int func(int a, int b) {
	int r;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return b;
}

int main() {
	int t, n;
	int num, i, j;

	scanf("%d", &t);


	arr[1] = 1;
	arr[0] = 1;
	for (i = 2; i*i <= 1000000; i++) {
		if (arr[i] == 1)
			continue;

        for (j = 2; i * j <= 1000000; j++) {
            arr[i * j] = 1;
		}
	}

	while (t--) {
		scanf("%d", &n);
		num = 0;
		for (i = 2; i <= n / 2; i++) {
			if (arr[i] == 0) {
				if (arr[n - i] == 0)
					num++;
			}
		}


		printf("%d\n", num);
	}

	return 0;
}