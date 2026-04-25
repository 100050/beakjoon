#include <stdio.h>
#include <string.h>

int main() {
    int i, t;
    char a[1000000];
    i = 0;
    t = 0;
    while (scanf("%s", a) == 1) {
        t++;
    }
    printf("%d", t);
}