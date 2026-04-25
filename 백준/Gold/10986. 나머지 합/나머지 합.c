#include <stdio.h>
#include <stdlib.h>

int main() {
    long res, n, m;
    long i;
    long* arr;
    long arr2[1000] = { 0, };
    scanf("%ld %ld", &n, &m);
    arr = (long*)malloc(sizeof(long) * (n+1));
    arr[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%ld", &arr[i]);
        arr[i] = (arr[i] +arr[i - 1]) % m;
        arr2[arr[i]]++;
    }
    res = arr2[0];
    for (i = 0; i < m; i++) {
        res += (arr2[i] * (arr2[i] - 1)) / 2;
    }

    printf("%ld", res);

    free(arr);
    return 0;
}