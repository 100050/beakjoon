#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, f, b;
    int* que;
    f = 0;
    scanf("%d", &n);
    que = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        que[i] = i + 1;
    }
    b = n - 1;
    for (i = 1; i <= 2 * n - 3; i++) {
        if (i % 2 == 1) {
            que[f++] = 0;
        }
        else {
            b++;
            if (b == n) {
                b = 0;
            }
            que[b] = que[f];
            que[f++] = 0;
            if (b == n) {
                b = 0;
            }
        }
        if (f == n) {
            f = 0;
        }
    }
    printf("%d", que[b]);

    free(que);
}