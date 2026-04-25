#include <stdio.h>

int main() {
    int n, i, t, a;
    t = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%1d", &a);
        t += a;
    }
    printf("%d", t);
}