#include <stdio.h>

int main() {
    long long i, n, j;
    i = 1;
    scanf("%lld", &n);
    for (j = 1; n > i; j++) {
        i += 6 * j;
    }
 

    printf("%lld", j);
}