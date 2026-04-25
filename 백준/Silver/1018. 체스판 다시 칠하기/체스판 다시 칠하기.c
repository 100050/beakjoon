#include <stdio.h>

int main() {
	char board[50][50];
	int width, length, i, j, k, g, total, min;
	scanf("%d %d", &width, &length);
	for (i = 0; i < width; i++) {
		for (j = 0; j < length; j++) {
			scanf("%1s", &board[i][j]);
		}
	}
	min = 64;
	for (k = 0; k + 7 < width; k++) {
		for (g = 0; g + 7 < length; g++) {
			total = 0;
			for (i = k; i < 8+k; i++) {
				for (j = g; j < 8+g; j++) {
					if ((i + j) % 2 == 0 && board[i][j] == 'B') total++;
					if ((i + j) % 2 == 1 && board[i][j] == 'W') total++;
				}
			}
			if (total > 32) total = 64 - total;
			if (total < min) min = total;
		}
	}
	printf("%d", min);

	return 0;
}