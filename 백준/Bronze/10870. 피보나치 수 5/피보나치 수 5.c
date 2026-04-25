#include <stdio.h>

long long a = 0, t = 1, b;
void p(int n);
int main() {
    int n;
    scanf("%d", &n);
    p(n);
    printf("%lld", t);
}

void p(int n) {
    if (n == 0) {
        n = 1;
        t = 0;
    }
    else if (n != 1) {
        b = t;
        t += a;
        a = b;
        n--;
        p(n);
    }
}
