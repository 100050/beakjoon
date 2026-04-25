#include <stdio.h>
#include <stdlib.h>

int main() {
    long* d, *p;
    long min;
    long long sum = 0;
    int i, n;
    scanf("%d", &n);
    d = (long*)malloc(sizeof(long) * (n - 1));
    p = (long*)malloc(sizeof(long) * n);
    for (i = 0; i < n-1; i++) {
        scanf("%ld", &d[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%ld", &p[i]);
    }
    min = p[0];
    for (i = 0; i < n - 1; i++) {
        sum += d[i] * min;
        if (min > p[i + 1]) {
            min = p[i + 1];
        }
    }

    printf("%lld", sum);

    free(d);
    free(p);
    return 0;
}