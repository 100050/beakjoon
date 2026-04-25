#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    long long n, b, i, j, k, l;
    char str[31] = "";

    scanf("%lld %lld", &n, &b);

    k = 1;
    i = 1;
    while (n >= i * b) {
        i *= b;
        k++;
    }
    for (i = 0; i < k; i++) {
        str[i] = '0';
    }

    while (n != 0) {
        l = k - 1;
        i = 1;
        while (n >= i * b) {
            i *= b;
            l--;
        }
        j = 1;
        while (n >= i * (j + 1)) {
            j++;
        }

        if (j >= 10) {
            str[l]  = j + 55;
        }
        else {
            str[l] = j + 48;
        }
        n %= i * j;
    }


    printf("%s", str);

    return 0;
}