#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int n;

void func(int d, int a) {
    if (d == 0) {
        if (a == 1)
            printf("-");
        else
            printf(" ");
        return 0;
    }

    func(d-1, a*1);
    func(d-1, a*0);
    func(d-1, a*1);

    return 0;
}

int main() {

    while (scanf("%d", &n) != EOF) {
        func(n, 1);
        printf("\n");
    }

    return 0;
}