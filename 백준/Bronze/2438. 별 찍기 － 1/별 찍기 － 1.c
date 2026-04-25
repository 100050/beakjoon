#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}