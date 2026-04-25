#include <stdio.h>

int main() {
    int arr[100];
    int n, m, i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    while(m--) {
        int a, b, temp;
        scanf("%d %d", &a, &b);
        temp = arr[a-1];
        arr[a-1] = arr[b-1];
        arr[b-1] = temp;
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}