#include <stdio.h>

long long res = 1;

void pibo(int d) {
    if (d <= 1) {
        printf("%lld", res);
        return;
    }
    res *= d;
    d -= 1;
    pibo(d);
    
    return;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    pibo(n);
}