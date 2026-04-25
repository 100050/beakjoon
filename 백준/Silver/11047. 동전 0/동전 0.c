#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, k, i, t;
    long long* arr;
    scanf("%lld %lld", &n, &k);
    arr = (long long*)malloc(sizeof(long long)*n);
    for (i= 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    t = 0;
    for (i = n-1; i >= 0; i--) {
        if (k <= 0)
            break;
        if (k >= arr[i]) {
            t += k / arr[i];
            k %= arr[i];
        }
    }
    printf("%lld", t);
    free(arr);
}