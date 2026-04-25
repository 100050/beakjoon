#include <stdio.h>

int main() {
    long long i, a, b, c;
    i = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    /*while (a / (c - b) >= i) {
        i++;
    }*/
    if (b < c) {
        i = a / (c - b) + 1;
    }
    else {
        i = -1;
    }
    printf("%lld", i);
}