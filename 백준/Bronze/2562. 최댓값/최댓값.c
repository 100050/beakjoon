#include <stdio.h>

int main() {
    int a[9];
    int i, max, n;
    max = 0;
    for (i = 0; i < 9; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 9; i++) {
        if (max < a[i]) {
            max = a[i];
            n = i+1;
        }
    }
    printf("%d\n%d", a[n-1], n);
}