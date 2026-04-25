#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, idx;
    int num[10000] = { 0, };

    while (1) {
        scanf("%d", &n);
        if (n == -1)
            break;
           
        j = 0;
        idx = 0;
        for (i = 1; i < n; i++) {
            if (n % i == 0) {
                j += i;
                num[idx++] = i;
            }
        }

        if (j == n) {
            printf("%d = %d", n, num[0]);
            for (i = 1; i < idx; i++) {
                printf(" + %d", num[i]);
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", n);
        }
    }

    return 0;
}