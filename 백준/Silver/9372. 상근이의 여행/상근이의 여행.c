#include <stdio.h>

int main() {
    int t;
    int i, a, b;
    int m, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &m, &n);
        for (i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            a = b;
            b = a;
        }
        printf("%d\n", m - 1);
    }
}