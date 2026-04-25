#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j, max;
    int arr[500][500];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    max = arr[0][0];
    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
            }
            else if (j == i) {
                arr[i][j] += arr[i - 1][j - 1];
            }
            else if (arr[i - 1][j-1] > arr[i - 1][j]) {
                arr[i][j] += arr[i - 1][j-1];
            }
            else {
                arr[i][j] += arr[i - 1][j];
            }
            if (max < arr[i][j]) max = arr[i][j];
        }
    }
    printf("%d", max);
}