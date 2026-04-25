#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int t, i, c;
    int arr[4] = { 0, };
    int coin[4] = { 25, 10, 5, 1 };
    int res;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &c);

        for (i = 0; i < 4; i++) {
            res = 0;
            arr[i] = 0;
            while (c >= coin[i]) {
                c -= coin[i];
                res++;
            }

            arr[i] = res;
        }

        for (i = 0; i < 4; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}