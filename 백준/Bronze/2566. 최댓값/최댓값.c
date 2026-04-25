#include <stdio.h>

int main() {
    int arr[9][9];
    int i, j, max = -1, x, y;
    for (i = 1; i<= 9; i++) {
        for (j = 1; j <= 9; j++) {
            scanf("%d", &arr[i][j]);
            if (max < arr[i][j]) {
                max  = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n%d %d", max, x, y);
}