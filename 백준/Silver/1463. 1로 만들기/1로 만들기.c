#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000001];

int main() {
    int x, i;
    scanf("%d", &x);
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (i = 4; i <= x; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 3 == 0 && arr[i / 3] + 1 < arr[i]) {
            arr[i] = arr[i / 3] + 1;
        }
        if (i % 2 == 0 && arr[i/2] +1 < arr[i]) {
            arr[i] = arr[i / 2] + 1;
        }
    }
    printf("%d", arr[x]);
}