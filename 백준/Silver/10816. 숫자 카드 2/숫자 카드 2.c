#include <stdio.h>
#include <stdlib.h>

typedef struct Arr {
    int val;
    int count;
}Arr;

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

void bin_search(Arr* arr, int key, int size) {
    int front, mid, back;
    front = 0; back = size - 1;
    while (1) {
        mid = (front + back) / 2;
        if (arr[mid].val == key) {
            printf("%d ", arr[mid].count);
            break;
        }
        
        if (back <= front) {
            printf("0 ");
            break;
        }

        if (arr[mid].val < key)
            front = mid + 1;
        else
            back = mid - 1;
    }
}


int main() {
    int n = 0, m = 0;
    int* arr, * arr2;
    Arr* arr3;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    arr3 = (Arr*)malloc(sizeof(Arr) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr3[i].count = 0;
    }

    scanf("%d", &m);
    arr2 = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    int idx = 0, len = 1;
    qsort(arr, n, sizeof(int), compare);
    arr3[0].val = arr[0];
    arr3[0].count++;
    for (int i = 1; i < n; i++) {
        if (arr3[idx].val != arr[i]) {
            arr3[++idx].count++;
            arr3[idx].val = arr[i];
            len++;
        }
        else {
            arr3[idx].count++;
        }
    }
    int total;
    for (int i = 0; i < m; i++) {
        bin_search(arr3, arr2[i], len);
    }

    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}