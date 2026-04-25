#include <stdio.h>
#include <stdlib.h>

int func(int a, int b, int c) {

    if (b == 1) {
        return a % c;
    }
    long long res = func(a, b / 2, c);
    if (b & 1) {
        return ((res * res) % c * a) % c;
    }
    else {
        return (res * res) % c;
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a %= c;

    printf("%d", func(a % c, b, c));

    return 0;
}