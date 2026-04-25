#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
    if (*a < *b)    return -1;
    else if (*a > *b)	return 1;
    else    return 0;
}

int main() {
    int c, n, result, distance, count, start;
    int i;
    int left, right, mid;
    int* arr;
    scanf("%d %d", &n, &c);
    arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    left = 1;
    right = arr[n - 1] - arr[0];
    while (left <= right) {
        mid = (left + right) / 2;
        start = arr[0];
        count = 1;
        for (i = 0; i < n; i++) {
            distance = arr[i] - start;
            if (mid <= distance) {
                count++;
                start = arr[i];
            }
        }

        if (count >= c) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%d", result);

    free(arr);
    return 0;
}