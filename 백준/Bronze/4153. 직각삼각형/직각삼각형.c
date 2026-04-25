#include <stdio.h>

int main() {
    int a, b, c, max, r;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) {
            break;
        }
        if (a > b && a > c) {
            if (a * a == b * b + c * c) r = 1;
            else r = 0;
        }
        else if (b > a && b > c) {
            if (b * b == a * a + c * c) r = 1;
            else r = 0;
        }
        else {
            if (c * c == b * b + a * a) r = 1;
            else r = 0;
        }
        if (r == 1) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }

    }
}