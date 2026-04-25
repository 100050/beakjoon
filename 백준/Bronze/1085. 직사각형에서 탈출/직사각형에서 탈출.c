#include <stdio.h>

int main() {
    int x,y,w,h,reach;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    reach = x;
    if (reach > y) reach = y;
    if (reach > w - x) reach =  w - x;
    if (reach > h - y) reach = h - y;

    printf("%d", reach);
}