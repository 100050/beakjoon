#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long n, m, i, max = 0;
    long long* arr;
    scanf("%lld %lld", &n, &m);
    arr = (long long*)malloc(sizeof(long long) * n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    long long left, right, len, mid, max_len = 0;
    left = 0;
    right = max;
    while (left <= right) {
        mid = (right + left) / 2;
        len = 0;
        for (i = 0; i < n; i++) {
            if (arr[i] > mid)
                len += arr[i] - mid;
        }

        if (mid > max_len && len >= m)
            max_len = mid;

        if (len < m) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("%lld", max_len);
    free(arr);
}