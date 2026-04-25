#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, idx, num;
    int arr[1001] = { 0, };
    int stack[1001] = { 0, };

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    idx = 0;
    i = 0;
    num = 1;
    j = 0; // 2 3 4 1
    while (i < n || idx > 0) {
        if (arr[i] == num) {
            arr[i] = 0;
            num++;
            i++;
            j++;
        }
        else if (stack[idx - 1] == num) {
            stack[idx - 1] = 0;
            num++;
            idx--;
            j++;
        }
        else if (i < n) {
            stack[idx] = arr[i];
            arr[i] = 0;
            i++;
            idx++;
        }
        else
            break;
    }

    if (j == n)
        printf("Nice");
    else
        printf("Sad");

    return 0;
}