#include <stdio.h>
#include <stdlib.h>

int heap[100000];
int heapCount = 0;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int x) {
    heap[++heapCount] = x;

    int child = heapCount;
    int parent = child / 2;

    while (child > 1 && abs(heap[child]) <= abs(heap[parent])) {
        if (abs(heap[child]) < abs(heap[parent])) {
            swap(&heap[child], &heap[parent]);
        }
        else if (abs(heap[child]) == abs(heap[parent]) && heap[child] < heap[parent]) {
            swap(&heap[child], &heap[parent]);
        }
        child = parent;
        parent = child / 2;
    }

}

void pop() {
    int ret = heap[1];
    if (heapCount == 0) {
        printf("0\n");
        return 0;
    }
    else {
        printf("%d\n", ret);
    }
    swap(&heap[1], &heap[heapCount]);
    heapCount = heapCount - 1;

    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= heapCount) {
        if (abs(heap[child]) < abs(heap[child + 1])) {
            child;
        }
        else if (abs(heap[child]) == abs(heap[child + 1]) && heap[child] < heap[child + 1]) {
            child;
        }
        else {
            child++;
        }
    }

    while (child <= heapCount && abs(heap[child]) <= abs(heap[parent])) {
        if (abs(heap[child]) < abs(heap[parent])) {
            swap(&heap[child], &heap[parent]);
        }
        else if (abs(heap[child]) == abs(heap[parent]) && heap[child] < heap[parent]) {
            swap(&heap[child], &heap[parent]);
        }
        parent = child;
        child = parent * 2;

        if (child + 1 <= heapCount) {
            if (abs(heap[child]) < abs(heap[child + 1])) {
                child;
            }
            else if (abs(heap[child]) == abs(heap[child + 1]) && heap[child] < heap[child + 1]) {
                child;
            }
            else {
                child++;
            }
        }
    }
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) pop();
        else push(x);
    }

    return 0;
}