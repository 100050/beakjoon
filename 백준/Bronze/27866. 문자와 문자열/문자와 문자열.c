#include <stdio.h>

int main() {
    char str[1001];
    int n;
    scanf("%s", str);
    scanf("%d", &n);
    printf("%c", str[n-1]);
}