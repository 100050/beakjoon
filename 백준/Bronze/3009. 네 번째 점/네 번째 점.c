#include <stdio.h>

int main() {
    int x,y,i;
    int arrx[1000] = {0, };
    int arry[1000] = { 0, };
    for (i = 0; i < 3; i++) {
        scanf("%d %d", &x, &y);
        arrx[x-1]++;
        arry[y-1]++;
    }
    for (i = 0; i < 1000; i++) {
        if (arrx[i] == 1) {
            x = i + 1;
        }
        if (arry[i] == 1) {
            y = i + 1;
        }
    }
    printf("%d %d",x,y);
}