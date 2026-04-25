#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int a;
	int b;
}Arr;

int compare(const void* a, const void* b) {
	if (((Arr*)a)->a > ((Arr*)b)->a) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int i, j;
	Arr arr[100] = { 0, };
	int l[100] = { 0, };
	int n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].a, &arr[i].b);
	}

	qsort(arr, n, sizeof(Arr), compare);
	int max = 0;
	l[0] = 1;
	for (i = 1; i < n; i++) {
		l[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[i].b > arr[j].b) {
				if (l[i] < l[j] + 1) {
					l[i] = l[j] + 1;
				}	
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (max < l[i])
			max = l[i];
	}

	printf("%d", n - max);
}