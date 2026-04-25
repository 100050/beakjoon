#include <stdio.h>

int main() {
    float m;
    float arr[1000] = {0, };
    int i, n, a, max;
    scanf("%d", &n);
    max = 0;
    m = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (max < a) {
            max = a;
        }
        arr[i] = a;
    }
    for (i = 0; i < n; i++) {
        m += (arr[i] / max) * 100;
    }
    m /= n;
   
    printf("%f", m);
}