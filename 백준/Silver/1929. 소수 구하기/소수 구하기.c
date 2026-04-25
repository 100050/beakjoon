#include <stdio.h>
#include <math.h>

int main() {
    long long n, i, j, m, b;
    scanf("%lld %lld",&m ,&n);
    for (i = m; i <= n; i++) {
        b = 1;
        for (j = 2; j <= (int)sqrt(i); j++) { // 소수 판별
            if (i % j == 0) {
                b = 0;
                break;
            }
        }
        if (b == 1 && i != 1) {
            printf("%lld\n", i);
        }
    }

    return 0;
}