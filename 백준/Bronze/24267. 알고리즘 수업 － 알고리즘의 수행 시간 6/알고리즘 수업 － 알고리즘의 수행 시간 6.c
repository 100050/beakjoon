#include <stdio.h>

int main() {
    long long n;
    
    scanf("%lld", &n);
    
    printf("%lld\n", n * (n - 1) * (n - 2) / 6);
    printf("3");
}