#include <stdio.h>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if (m - 45 < 0) {
        if (h - 1 < 0) {
            printf("23 %d", m +15);
        }
        else {
            printf("%d %d", h - 1, m + 15);
        }
    }
    else {
        printf("%d %d", h, m - 45);
    }
    
    return 0;
}