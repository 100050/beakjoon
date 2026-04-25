#include <stdio.h>

int n;
int j;

void star(int i) {

	if (i == 2 * n - 1) {
		for (j = 0; j < n * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");

		return;
	}

	for (j = 0; j < (n * 2 - 1 - i) / 2; j++) {
		printf(" ");
	}
	for (j = 0; j < i; j++) {
		printf("*");
	}

	printf("\n");
	
	star(i + 2);

	for (j = 0; j < (n * 2 - 1 - i) / 2; j++) {
		printf(" ");
	}
	for (j = 0; j < i; j++) {
		printf("*");
	}

	printf("\n");

}

int main() {

	scanf("%d", &n);

	star(1);
	
	return 0;
}