#include <stdio.h>
#include <math.h>
#define MAX 10001
int main() {
    short arr[MAX] = { 0, };
    long long i, j, n, t, a, b, k;
    a = 0;
    b = 0;
    for (i = 2; i <= sqrt(MAX); i++) {
        if (arr[i] == 0) {
            for (j = 2; i * j < MAX; j++) {
                arr[i * j] = 1;
            }
        }
    }
    arr[1] = 1;
    scanf("%lld", &t);
    for (j = 0; j < t; j++) {
        scanf("%lld", &n);
        for (i = n/2; i < n; i++) {
            if (arr[i] == 0) {
                a = i;
                if (arr[n - a] == 0) {
                    b = n - a;
                    break;
                }
            }
        }
        printf("%lld %lld\n", b, a);
    }

    return 0;
}