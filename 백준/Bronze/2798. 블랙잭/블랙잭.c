#include <stdio.h>

int main() {
    int i,j,k,n,m,t;
    t = 0;
    int arr[100];
    scanf("%d %d", &n, &m);
    for (i = 0; i< n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            for (k =j+1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] > t && arr[i] + arr[j] + arr[k] <= m) {
                    t = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    printf("%d", t);
}