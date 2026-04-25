#include <stdio.h>

int main() {
    int n, k, i, c = 0;
    scanf("%d %d", &n, &k);
    
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            c++;
        }
        if (c == k) {
            printf("%d", i);
            return 0;
        }
    }
    
    printf("0");
    
    return 0;
}