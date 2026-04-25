#include <stdio.h>

int main() {
    int n, i, res = 1;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        res *= 2;
    }
    
    printf("%d", res);
}