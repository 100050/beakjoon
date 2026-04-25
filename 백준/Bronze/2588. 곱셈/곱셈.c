#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d\n%1d%1d%1d", &a, &b, &c, &d);
    printf("%d\n", a * d);
    printf("%d\n", a * c);
    printf("%d\n", a * b);
    printf("%d", a * b * 100 + a * c * 10 + a * d);
}