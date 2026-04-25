#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int b, i, j, k, l, ret = 0;
    char n[31] = "";

    scanf("%s %d", n, &b);
    l = strlen(n);
    i = l - 1;
    
    while (i != -1) {
        k = 1;
        for (j = i; j < l - 1; j++) {
            k *= b;
        }
        if (n[i] >= 65) {
            ret += (n[i] - 55) * k;
        }
        else {
            ret += (n[i] - 48) * k;
        }
        i--;
    }


    printf("%d", ret);

    return 0;
}