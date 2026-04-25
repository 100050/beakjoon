#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, c;
    int n, i;
    char str[5] = { 0, };
    
    scanf("%d\n%s\n%d", &a, &str, &c);
    
    i = strlen(str);
    n = 1;
    for (int j = 0; j < i; j++) {
        n *= 10;
    }
    b = atoi(str);
    
    printf("%d\n", a + b - c);
    printf("%d", a * n + b - c);
}