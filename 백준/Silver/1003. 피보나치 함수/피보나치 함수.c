#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n;
    scanf("%d", &t);
    int one[41] = { 0, };
    int zero[41] = { 0, };
    one[0] = 0;
    one[1] = 1;
    zero[1] = 0;
    zero[0] = 1;
    for (int i = 2; i <= 40; i++) {
        one[i] = one[i - 1] + one[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
    }
    while (t--) {
        scanf("%d", &n);
        printf("%d %d\n", zero[n], one[n]);
    }

    return 0;
}