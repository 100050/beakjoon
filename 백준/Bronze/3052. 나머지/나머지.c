#include <stdio.h>

int main() {
    int a, i, t;
    int arr[1000] = {0};
    t = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &a);
        arr[a%42] = 1;
    }
    for (i = 0; i < 1000; i++) {
        if (arr[i]) {
            t++;
        }
    }
    printf("%d", t);
}