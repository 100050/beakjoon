#include <stdio.h>
#include <stdlib.h>

int arr[128][128] = { 0, };
int color[2] = { 0, };

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
        color[prev]++;
        return;
    }
    else {
        d(n / 2, x, y);
        d(n / 2, n/2 + x, y);
        d(n / 2, x, n/2 + y);
        d(n / 2, n/2 + x, n/2 + y);
        
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

    printf("%d\n%d", color[0], color[1]);

    return 0;
}