#include <stdio.h>
int main() {
    long long a, b, v, n;
    scanf("%lld %lld %lld", &a, &b, &v);
    n = (v - b) / (a - b);
    if (a * n - b * (n - 1) >= v) {
        printf("%lld", n);
    }
    else {
        printf("%lld", n + 1);
    }
}