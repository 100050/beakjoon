#include <stdio.h>
#include <math.h>

int main() {
    long long l, i, j, t, r, a;
    char str[50];
    scanf("%lld", &l);
    scanf("%s", str);
    j = 0;
    t = 0;
    for (i = 0; i < l; i++) {
        r = 1;
        for (j = 0; j < i; j++) {
            r = (r*31) % 1234567891;
        }
        a = (int)str[i] - 96;
        t += (a*r);
        t %= 1234567891;
        j++;  
    }
    printf("%lld", t);
}