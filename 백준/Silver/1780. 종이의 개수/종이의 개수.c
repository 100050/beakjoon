#include <stdio.h>
#include <stdlib.h>

char arr[2187][2187] = { 0, };
int color[3] = { 0, };

void d(int n, int x, int y) {
    int i, j, b = 1;
    int prev = arr[y][x];
    for (i = y; i < n + y; i++) {
        for (j = x; j < n + x; j++) {
            if (prev != arr[i][j]) {
                b = 0;
                break;
            }
        }
        if (b == 0) break;
    }
    if (b == 1) {
        color[++prev]++;

        return;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                d(n / 3, j * n / 3 + x, i * n / 3 + y);
            }
        }
        return;
    }
}

int main() {
    int n;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    d(n, 0, 0);

    printf("%d\n%d\n%d", color[0], color[1], color[2]);

    return 0;
}