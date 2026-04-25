#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr, *dp;
    int n, max;
    int i, j;
    scanf("%d", &n);
    dp = (int*)malloc(sizeof(int) * n);
    arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    dp[0] = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[i] + dp[i - 1]) 
            dp[i] = arr[i];
        else 
            dp[i] = arr[i] + dp[i - 1];

        if (max < dp[i]) 
            max = dp[i];
    }

    printf("%d", max);

    free(arr);  
    free(dp);
    return 0;
}