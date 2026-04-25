#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[51];
    char arr[7];
    int num;
    int ret = 0, len, i, j, s = 0, b = 0;
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-') {
            for (j = s; j < i; j++) {
                arr[j - s] = str[j];
            }
            arr[j - s] = NULL;
            s = j;
            num = atoi(arr);
            if (num < 0) {
                ret += num;
                b = 1;
            }
            else {
                if (b == 1) {
                    ret -= num;
                }
                else {
                    ret += num;
                }
            }
        }
    }
    for (j = s; j < i; j++) {
        arr[j - s] = str[j];
    }
    arr[j - s] = NULL;
    num = atoi(arr);
    if (num < 0) {
        ret += num;
        b = 1;
    }
    else {
        if (b == 1) {
            ret -= num;
        }
        else {
            ret += num;
        }
    }

    printf("%d", ret);
    
    return 0;
}