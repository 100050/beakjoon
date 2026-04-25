#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[3] = { 0, };
    int max = 0;
    int i;
    int d = 0;

    for (i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 0; i < 3; i++) {
        d += arr[i];
    }
    if (d - max <= max) {
        d -= 2 * max - d + 1;
    }

    printf("%d", d);

}