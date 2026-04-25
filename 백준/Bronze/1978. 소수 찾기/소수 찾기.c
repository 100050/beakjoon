#include <stdio.h>

int main() {
    int n, a, i, j, b;
    scanf("%d", &n);
    b = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) {
            b--;
            continue;
        }
        for (j = 2; j < a; j++) {
            if (a % j == 0) {
                b--;
                break;
            }
        }
    }
    printf("%d", n + b);
}