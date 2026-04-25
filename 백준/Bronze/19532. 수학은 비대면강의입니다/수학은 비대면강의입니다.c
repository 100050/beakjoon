#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    int x, y;
    int i, j;
    int bol = 0;
    
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    for (i = -999; i <= 999; i++) {
        for (j = -999; j <= 999; j++) {
            if (a * i + b * j == c && d * i + e * j == f) {
                x = i;
                y = j;
                bol = 1;
                break;
            }
        }
        if (bol == 1) break;
    }
    
    printf("%d %d", x, y);
}