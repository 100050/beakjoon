#include <stdio.h>
int main() {
    long long h, w, n, t, r, i;
    scanf("%lld", &t);
    for (i = 0; i < t; i++) {
        scanf("%lld %lld %lld", &h, &w, &n);
        if (n%h == 0) {
            r = h * 100 + n/h;
        }
        else {
            r = (n % h) * 100 + n / h + 1;
        }
        printf("%lld\n", r);
    }
}