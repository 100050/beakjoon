#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long arr;
    long long arr2;
} Arr;

q(Arr* arr, long long L, long long R) {
    long long right = R, left = L, temp;
    long long pivot = arr[(R + L) / 2].arr2;
    do {
        while (arr[right].arr2 > pivot) {
            right--;
        }
        while (arr[left].arr2 < pivot) {
            left++;
        }
        if (left <= right) {
            temp = arr[left].arr;
            arr[left].arr = arr[right].arr;
            arr[right].arr = temp;
            temp = arr[left].arr2;
            arr[left].arr2 = arr[right].arr2;
            arr[right].arr2 = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (left < R) {
        q(arr, left, R);
    }
    if (right > L) {
        q(arr, L, right);
    }
}

q2(Arr* arr, long long L, long long R) {
    long long right = R, left = L, temp;
    long long pivot = arr[(R + L) / 2].arr;
    do {
        while (arr[right].arr > pivot) {
            right--;
        }
        while (arr[left].arr < pivot) {
            left++;
        }
        if (left <= right) {
            temp = arr[left].arr;
            arr[left].arr = arr[right].arr;
            arr[right].arr = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (left < R) {
        q2(arr, left, R);
    }
    if (right > L) {
        q2(arr, L, right);
    }
}

int main() {
    long long n, i, t, b, j;
    scanf("%lld", &n);
    Arr* arr;
    arr = (Arr*)malloc(sizeof(Arr) * n);
    for (i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].arr, &arr[i].arr2);
    }
    q(arr, 0, n - 1);
    for (i = 0; i < n; i++) {
        for (j = i; arr[i].arr2 == arr[j].arr2; j++);
        if (j - 1 != i)
            q2(arr, i, j-1);
        if (j == n)
            break;
    }
    b = arr[0].arr2;
    t = 1;
    for (i = 1; i < n; i++) {
        if (b <= arr[i].arr) {
            t++;
            b = arr[i].arr2;
        }
    }
    printf("%lld", t);

    free(arr);
}