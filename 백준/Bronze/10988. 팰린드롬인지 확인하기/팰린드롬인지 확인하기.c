#include <stdio.h>
#include <string.h>

int main() {
    int i, b = 1, len;
    char str[101];
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len - i - 1]) {
            b = 0;
            break;
        }
    }
    printf("%d", b);
}