#include <stdio.h>

long long t = 1;
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
    }
    else if (n != 1) {
        t *= n;
        n--;
        p(n);
    }
}

