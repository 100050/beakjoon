#include <stdio.h>

int N, K;
long long m[4000001] = {1, };
long long mod = 1000000007;
long long pow_(long long a, long long b) {
    
    if(b == 1)
        return a;
    
    long long result = pow_(a, b / 2) % mod;
    result = (result * result) % mod;
    
    if(b % 2)
        result = (result * a) % mod;
    
    return result;
    
}

int main() {
    
    scanf("%d %d", &N, &K);
    
    for(int i = 1; i <= N; i++) {
        m[i] = (i * m[i - 1]) % mod;
    }
    
    
    printf("%lld", (m[N] *pow_((m[N-K]*m[K])%mod , mod - 2))%mod);
}