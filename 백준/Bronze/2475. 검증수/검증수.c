#include <stdio.h>

int main() {
    int a, t, i;
    t = 0;
    for (i = 0; i < 5; i++) {
        scanf("%d ", &a);
        t += a*a;
    }
    printf("%d", t%10);
}