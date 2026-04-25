#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int main() {
    int n, i, front, back, min, a, b;
    int* arr;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    front = 0;
    back = n - 1;
    min = abs(arr[front] + arr[back]);
    a = front;
    b = back;
    while (front < back) {
        if (min > abs(arr[front] + arr[back])) {
            min = abs(arr[front] + arr[back]);
            a = front;
            b = back;
        }
        else {
            if (abs(arr[front]) > abs(arr[back])) {
                front++;
            }
            else {
                back--;
            }
        }
    }
    printf("%d %d", arr[a], arr[b]);

    free(arr);
    return 0;
}