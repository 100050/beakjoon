#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main() {
    int* arr;
    int n, x, i, l, r, s = 0;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);
    l = 0; r = n - 1;
    while (l < r) {
        if (x == arr[l] + arr[r]) {
            s++;
        }
        if (x > arr[l] + arr[r]) {
            l++;
        }
        else {
            r--;
        }
    }

    printf("%d", s);

    free(arr);
    return 0;
}