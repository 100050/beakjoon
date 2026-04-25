#include <stdio.h>

int main() {
    int t, r, i, j, k;
    char s[20];
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        k = 0;
        scanf("%d %s", &r, s);
        while(s[k] != '\0') {
            for (j = 0; j < r; j++) {
                printf("%c", s[k]);
            }
            k++;
        }
        printf("\n");
    }
}