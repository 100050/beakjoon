#include <stdio.h>
#include <math.h>
#define MAX 123456 * 2 + 1
int main() {
    short a[MAX] = { 0 };
    long long i, j, n, t;
    for (i = 2; i <= sqrt(MAX); i++) {
        if (a[i] == 0) {
            for (j = 2; i * j < MAX; j++) {
                a[i * j] = 1;
            }
        }
    }
    while (1) {
        t = 0;
        scanf("%lld", &n);
        if (n == 0) {
            break;
        }
        for (i = n + 1; i <= 2 * n; i++) {
            if (a[i] == 0) {
                t++;
            }
        }
        printf("%lld\n", t);
    }

    return 0;
}