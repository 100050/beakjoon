#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr, *dp;
    int n, max, m;
    int i;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    dp = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }

    dp[1] += arr[0];
    max = dp[1];
    if (n == 1) {
        max = dp[0];
    }
    for (i = 2; i < n; i++) {
        if (i == 2) {
            if (dp[i - 2] > arr[i - 1]) {
                dp[i] += dp[i - 2];
            }
            else {
                dp[i] += arr[i - 1];
            }
        }
        else if (i >= 3) {
            if (dp[i - 2] > arr[i - 1] + dp[i - 3]) {
                dp[i] += dp[i - 2];
            }
            else {
                dp[i] += arr[i - 1] + dp[i - 3];
            }
        }
        if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
        if (max < dp[i]) max = dp[i];
    }

    printf("%d", max);

    free(arr);
    free(dp);
    return 0;
}