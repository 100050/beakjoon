#include <stdio.h>

int main() {
    int i, x, n, a, b, t;
    t = 0;
    scanf("%d\n%d", &x, &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        t += a*b;
    }
    if (t == x) {
        printf("Yes");
    }
    else {
        printf("No");
    }
}