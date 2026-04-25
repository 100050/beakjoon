#include <stdio.h>

int main() {
    int i, a;
    int arr[6] = {1, 1, 2, 2, 2, 8};
    for (i = 0; i < 6; i++) {
        scanf("%d ", &a);
        arr[i] -= a;
    }
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}