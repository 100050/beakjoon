#include <stdio.h>

int star(int x,int y,int n) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1) printf(" ");
	else {
		if (n / 3 == 0) printf("*");
		else star(x, y, n / 3);
	}
}

int main() {
	int n, i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			star(i, j, n);
		}
		printf("\n");
	}

	return 0;
}