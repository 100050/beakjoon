#include <stdio.h>

int main() {
	int a, b, i;
	int arr[8] = {0, };
	for (i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	a = 0, b = 0;
	for (i = 0; i < 8; i++) {
		if (arr[i] == i + 1) {
			a++;
		}
		if (arr[i] == 8 - i) {
			b++;
		}
	}

	if (a == 8) printf("ascending");
	else if (b == 8) printf("descending");
	else printf("mixed");
}