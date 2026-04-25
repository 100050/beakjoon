#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int* arr, *dp;
    int n;
    int i;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    dp = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }

    dp[1] += arr[0];
    for (i = 2; i < n; i++) {
        if (dp[i - 2] > arr[i - 1] + dp[i - 3]) {
            dp[i] += dp[i - 2];
        }
        else {
            dp[i] += arr[i - 1] + dp[i - 3];
        }
    }

    printf("%d", dp[n - 1]);

    free(arr);
    free(dp);
    return 0;
}