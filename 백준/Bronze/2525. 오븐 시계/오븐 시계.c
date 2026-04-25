#include <stdio.h>

int main() {
    int h, m, t, dh, dm;
    scanf("%d %d\n%d", &h, &m, &t);
    dm = m + t;
    dh = h + dm / 60;
    dm = dm % 60;
    dh = dh % 24;
    printf("%d %d", dh, dm);

    return 0;
}