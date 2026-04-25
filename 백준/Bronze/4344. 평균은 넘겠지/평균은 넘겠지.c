#include <stdio.h>

int main() {
    int i, c, j, n;
    float r, m, u;
    int arr[1000];
    scanf("%d", &c);
    for (i = 0; i < c; i++) {
        m = 0;
        u = 0;
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf(" %d", &arr[j]);
            m += arr[j];
        }
        m /= n;
        for (j = 0; j < n; j++) {
            if (arr[j] > m) {
                u += 1;
            }
        }
        r = u / n * 100;
        
        printf("%.3f%%\n", r);
    }
    
   
}