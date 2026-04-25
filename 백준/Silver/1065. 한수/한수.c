#include <stdio.h>
int main() {
    long long i, j, n, t;
    char arr[5] = "";
    scanf("%lld", &n);
    t = 0;
    for (i = 1; i <= n; i++) {
        if (i < 100) {
            t++;
        }
        else {
            sprintf(arr, "%lld", i);
            if ((int)arr[0] - (int)arr[1] == (int)arr[1] - (int)arr[2]) {
                t++;
            }
        }
    }
    printf("%lld", t);
}