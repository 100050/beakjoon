#include <stdio.h>

void self(int* arr) {
    int sum;
    for (int i = 1; i <= 10000; i++) {
        sum = i;
        for (int j = i; j > 0; j /= 10) {
            sum += j % 10;
        }
        if (sum > 10000) continue;
        arr[sum - 1] = 1;
    }
}

int main() {
    int i;
    int arr[10000] = { 0, };
    self(arr);
    for (i = 0; i < 10000; i++) {
        if (arr[i] == 0) {
            printf("%d\n", i+1);
        }
    }
}