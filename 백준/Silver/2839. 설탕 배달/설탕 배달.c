#include <stdio.h>
int main() {
    long long n, i, f, t, b;
    b = 0;
    scanf("%lld", &n);
    for (f = n/5; f >= 0; f--) {
        t = (n - f*5) / 3;
        if (f*5 + t*3 == n) {
            b = 1;
            break;
        }
    }
    if (b == 1) {
        printf("%lld", f + t);
    }
    else {
        printf("-1");
    }
}