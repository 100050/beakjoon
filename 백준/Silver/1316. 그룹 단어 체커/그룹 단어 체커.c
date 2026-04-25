#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
    int n, i, j, total, a, size;
    int arr[26] = {0, };
    char str[101];
    scanf("%d", &n);
    total = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            arr[j] = 0;
        }
        a = 1;
        scanf("%s", str);
        size = strlen(str);
        for (j = 0; j < size; j++) {
            if (size == 1) {
                break;
            }
            if (j == size - 1) {
                if (str[j - 1] != str[j] && arr[str[j] - 'a'] == 1) {
                    a = 0;
                    break;
                }
            }
            else if (j != 0) {
                if (str[j] != str[j - 1] && arr[str[j] - 'a'] == 1) {
                    a = 0;
                    break;
                }
            }
            arr[str[j] - 'a'] = 1;
        }
        total += a;
    }
    printf("%d", total);
}
