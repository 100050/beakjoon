#include <stdio.h>

int main() {
    int n, m, t, min, i, j;
    min = 10000;
    t = 0;
    scanf("%d\n%d",&m , &n);
    for (i = m; i <= n; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j == i) {
            t += i;
            if (min > i) {
                min = i;
            }
        }
    }
    if (t == 0) {
        printf("-1");
    }
    else {
        printf("%d\n%d", t, min);
    }
}