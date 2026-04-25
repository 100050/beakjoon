#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, idx = 0, left, right, mid;
    int n;
    int* a, *b;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    b = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    b[0] = a[0];
    for (i = 1; i < n; i++) {
        if (b[idx] < a[i]) {
            b[++idx] = a[i];
        }
        else {
            left = 0;
            right = idx;
            while (left <= right) {
                mid = (left + right) / 2;

                if (b[mid] >= a[i]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            b[left] = a[i];
        }
    }

    printf("%d", idx+1);

    free(a);
    free(b);
    return 0;
}