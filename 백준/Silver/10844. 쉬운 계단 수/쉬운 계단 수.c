#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000000
int main() {
    long long arr[100][10];
    long long n, i, j, sum = 0;
    scanf("%lld", &n);
    arr[0][0] = 0;
    for (i = 1; i < 10; i++) {
        arr[0][i] = 1;
    }
    for (j = 1; j < n; j++) {
        arr[j][0] = arr[j - 1][1];
        for (i = 1; i < 9; i++) {
            arr[j][i] = (arr[j - 1][i - 1] + arr[j - 1][i + 1]) % MOD;
        }
        arr[j][9] = arr[j - 1][8];
    }
    for (i = 0; i < 10; i++) {
        sum += arr[n - 1][i];
        sum %= MOD;
    }
    printf("%lld", sum);

    return 0;
}