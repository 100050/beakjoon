#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int t, b;
    long long n, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n <= 2) {
            printf("2\n");
            continue;
        }
        for (;;) {
            b = 1;
            for (i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    b = 0;
                    break;
                }
            }
            if (b == 1) {
                break;
            }
            n++;
        }
        printf("%lld\n", n);
    }
    
    return 0;
}