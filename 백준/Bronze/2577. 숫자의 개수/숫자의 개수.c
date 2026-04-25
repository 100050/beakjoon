#include <stdio.h>

int main() {
    int a, b, c, i;
    char r[12];
    int n[10] = {0};
    scanf("%d\n%d\n%d", &a, &b, &c);
    sprintf(r, "%d", a*b*c);
    for (i = 0; i < 12; i++) {
        switch (r[i]) {
        case '0': n[0] += 1; break;
        case '1': n[1] += 1; break;
        case '2': n[2] += 1; break;
        case '3': n[3] += 1; break;
        case '4': n[4] += 1; break;
        case '5': n[5] += 1; break;
        case '6': n[6] += 1; break;
        case '7': n[7] += 1; break;
        case '8': n[8] += 1; break;
        case '9': n[9] += 1; break;
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d\n", n[i]);
    }
    
}