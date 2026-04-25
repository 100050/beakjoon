#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int dot = 2;
    int n, i , j;

    //2^n승
    scanf("%d", &n);
    
    j = 1;
    for (i = 0; i < n; i++) {
        j *= 2;
    }
    dot += j - 1;

    printf("%d", dot * dot);

    return 0;
}