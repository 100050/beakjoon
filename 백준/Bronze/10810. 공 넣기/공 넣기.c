#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int i;
    int start, end, number;
    int* arr;
    scanf("%d %d", &n, &m);
    arr = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        arr[i] = 0;
    }
    
    while (m--) {
        scanf("%d %d %d", &start, &end, &number);
        for (i = start-1; i < end; i++) {
            arr[i] = number;
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}