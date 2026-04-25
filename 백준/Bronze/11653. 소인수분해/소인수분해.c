#include <stdio.h>
#include <math.h>
#define MAX 10000000
int main() {
    short a[MAX] = { 0 };
    long long i, j, n, t, k;
    t = 1;
    scanf("%lld", &n);
    for (i = 2; i <= sqrt(MAX); i++) {
        if (a[i] == 0) {	
            for (j = 2; i * j < MAX; j++) {
                a[i * j] = 1;
            }
        }
    }

    for (i = 2; i <= n; i++) {
        k = i;
        while (a[i] == 0 && n != 1 && n % k == 0) {
            printf("%lld\n", i);
            k *= i;
            t *= i;
        }
        if (n == t) {
            break;
        }
    }

    return 0;
}