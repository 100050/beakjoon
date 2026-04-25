#include <stdio.h>

int main() {
    int a, b, c, r = 0;
    scanf("%d %d\n%d", &a, &b, &c);
 
    int max = 0;
    max = ((a > b) && (a > c)) ? a : ((b > a) && (b > c)) ? b : c;
    if (a == b) {
        if (b == c) {
            r = 10000 + a * 1000;
        }
        else {
            r = 1000 + a * 100;
        }
    }
    else if (a == c){
        r = 1000 + a * 100;
    }
    else {
        if (b == c) {
            r = 1000 + b * 100;
        }
        else {
            r = max * 100;
        }
    }

    printf("%d", r);

    return 0;
}