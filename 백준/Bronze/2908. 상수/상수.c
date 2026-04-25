#include <stdio.h>

int main() {
    int c, d, e;
    int a, b;
    scanf("%d %d", &a, &b);
    c = a/100;
    d = a%100 - a%10;
    e = a%10;
    a = e*100 + d + c;
    c = b/100;
    d = b%100 - b%10;
    e = b%10;
    b = e*100 + d + c;
    if (a > b) {
        printf("%d", a);
    }
    else {
        printf("%d", b);
    }
}