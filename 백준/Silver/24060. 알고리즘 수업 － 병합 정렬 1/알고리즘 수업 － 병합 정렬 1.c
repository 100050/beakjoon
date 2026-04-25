#include <stdio.h>
#include <stdlib.h>
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
int ka, cnt, n, b;
b = -1;
cnt = 0;
int main() {
    int* data;
    int i;
    scanf("%d %d", &n, &ka);
    data = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    mergeSort(data, 0, n-1);
    printf("%d", b);
    free(data);
    return 0;
}
void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int* tmp; // 새 배열
    tmp = (int*)malloc(sizeof(int) * n);
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) {
        tmp[k++] = data[i++];
    }
    while (j <= r) {
        tmp[k++] = data[j++];
    }
    for (int a = p; a <= r; a++) {
        data[a] = tmp[a];
        cnt++;
        if (cnt == ka) {
            b = tmp[a];
        }
    }
    free(tmp);
}