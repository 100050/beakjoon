#include <stdio.h>

int main() {
	int i, j, k, time = 0;
	char arr[8][4] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	char str[15];
	scanf("%s", str);
	for (i = 0; str[i]; i++) {
		for (j = 0; j < 8; j++) {
			for (k = 0; arr[j][k]; k++) {
				if (arr[j][k] == str[i]) {
					if (arr[j][k] == 'T' || arr[j][k] == 'U' || arr[j][k] == 'V') time++;
					time += j + 3;
					j = 9;
					break;
				}
			}
		}
	}
	printf("%d", time);
}