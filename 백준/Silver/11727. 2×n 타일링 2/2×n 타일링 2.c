#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n;
    long long dp[1000];
    scanf("%lld", &n);
    dp[0] = 1;
    dp[1] = 3;
    for (long long i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    printf("%lld", dp[n - 1] % 10007);
    
    return 0;
}