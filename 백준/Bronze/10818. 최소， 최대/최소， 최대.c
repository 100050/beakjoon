#include <stdio.h>

int main() {
    int n, d, max, min, i;
    scanf("%d", &n);
    max = - 1000000;
    min = 1000000;
    for (i = 0; i < n; i++) {
        scanf("%d ", &d);
        if (max < d) {
            max = d;
        }
        if (min > d) {
            min = d;
        }
    }

    printf("%d %d", min, max);

    return 0;
}