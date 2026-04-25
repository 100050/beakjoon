#include <stdio.h>

int arr[9][9];
int p[81][2];
int v1[9][10]; // 가로
int v2[9][10]; // 세로
int v3[9][10]; // 3*3
int n;

int sol(int d) {
	if (d == n) {
		return 1;
	}
	int x, y;
    y = p[d][0];
    x = p[d][1];
    for (int j = 1; j <= 9; j++) {
        if (v1[y][j] == 0&& v2[x][j] == 0 && v3[(y / 3)*3 + x / 3][j] == 0) {
            v1[y][j] = 1;
            v2[x][j] = 1;
            v3[(y / 3)*3 + x / 3][j] = 1;
            arr[y][x] = j;
            if (sol(d + 1)) {
                return 1;
            }
            v1[y][j] = 0;
            v2[x][j] = 0;
            v3[(y / 3)*3 + x / 3][j] = 0;
        }
    }
	return 0;
}

int main() {
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				p[n][1] = j;
				p[n][0] = i;
				n++;
			}
            else {
                v1[i][arr[i][j]] = 1;
			    v2[j][arr[i][j]] = 1;
			    v3[(i/3)*3 + j/3][arr[i][j]] = 1;
            }
		}
	}

	sol(0);

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}