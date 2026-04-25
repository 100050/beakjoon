#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[6];
    scanf("%s", arr);
    while (arr[0] != '0') {
        int len = strlen(arr);
        int i = 0, t = 1;
        while (i <= (len - 1) / 2) {
            if (arr[i] != arr[len - i - 1]) {
                t = 0;
                break;
            }
            i++;
        }
        if (t == 1) printf("yes\n");
        else printf("no\n");
        scanf("%s", arr);
    }
}