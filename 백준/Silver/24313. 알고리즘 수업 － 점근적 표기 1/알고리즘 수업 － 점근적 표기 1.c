#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int a1, a0, c, n0;
    int i, b;

    scanf("%d %d\n%d\n%d", &a1, &a0, &c, &n0);

    b = 1;
    for (i = n0; i <= 100; i++) {
        if (a0 > (c - a1) * i) {
            b = 0;
            break;
        }
    }

    printf("%d", b);

    return 0;
}