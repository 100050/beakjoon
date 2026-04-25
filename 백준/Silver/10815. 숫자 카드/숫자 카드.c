#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int bin_search(int* arr, int key, int size) {
    int front, mid, back;
    front = 0; back = size - 1;
    while (1) {
        mid = (front + back) / 2;
        if (arr[mid] == key) return 1;
        if (arr[front] == key) return 1;
        if (arr[back] == key) return 1;

        if (arr[mid] < key)
            front = mid + 1;
        else
            back = mid - 1;
        if (back <= front) return 0;
    }
}

int main() {
    int n = 0, m = 0;
    int *arr, *arr2;

    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);
    arr2 = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < m; i++) {
        printf("%d ", bin_search(arr, arr2[i], n));
    }
    
    free(arr);
    free(arr2);
    
    return 0;
}