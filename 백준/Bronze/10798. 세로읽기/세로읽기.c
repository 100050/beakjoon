#include <stdio.h>
#include <stdlib.h>

int main() {
    char arr[6][16] = { 0,};
    int i, j;
    for (i = 0; i < 5; i++) {
        scanf("%s", arr[i]);
    }
    for (j = 0; j < 15; j++) {
        for (i = 0; i < 5; i++) {
            if (arr[i][j] == NULL)
                continue;
            else
                printf("%c", arr[i][j]);
        }
    }

    return 0;
}