#include <stdio.h>

int main() {
    int n, i, max, min, a;
    min = 1000000/2;
    max = 2;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d ", &a);
        if (a > max) max = a;
        if (a < min) min = a;
    }
    if (n == 0) printf("2");
    else printf("%d", max*min);
}