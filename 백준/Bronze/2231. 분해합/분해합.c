#include <stdio.h>

int main() {
    int b, i, j, n, t, temp;
    scanf("%d", &n);
    b = 0;
    for (i = 1; i <= n; i++) {
        temp = i;
        t = temp;
        do {
            t += temp % 10;
            temp /= 10;
        } while (temp / 10 != 0);
        t += temp;
        if (t == n) {
            b = i;
            break;
        }
    }
    if (b != 0) {
        printf("%d", b);
    }
    else {
        printf("0");
    }
}