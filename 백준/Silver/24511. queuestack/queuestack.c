#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;
int i, j, s;
int* aArr, * bArr, * cArr;

int main() {

    scanf("%d", &n);
    aArr = (int*)malloc(sizeof(int) * n);
    bArr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aArr[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &bArr[i]);
    }
    scanf("%d", &m);
    cArr = (int*)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++) {
        scanf("%d", &cArr[i]);
    }
    i = n - 1;
    s = 0;
    while (s != m) {
        if (aArr[i--] == 0) {
            printf("%d ", bArr[i + 1]);
            s++;
        }
        if (i < 0) {
            break;
        }
    }
    i = 0;
    while (s != m) {
        s++;
        printf("%d ", cArr[i++]);
    }

    free(aArr);
    free(bArr);
    free(cArr);
    return 0;
}