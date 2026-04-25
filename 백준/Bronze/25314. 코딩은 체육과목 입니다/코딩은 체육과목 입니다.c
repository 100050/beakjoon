#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    scanf("%d", &n);
    n = (int)ceil(n/4);
    for (i = 0; i < n; i++) {
        printf("long ");
    }
    printf("int");
    
    return 0;
}