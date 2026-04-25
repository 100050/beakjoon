#include <stdio.h>

int main() {
    int j ,i, n, a;
    int arr[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (j = 0; j < n-1; j++) {
        for (i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                a = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = a;
            }
        }    
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}