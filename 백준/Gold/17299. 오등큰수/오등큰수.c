#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[1000000];
int nge[1000001];
int stack[1000000];

int main() {
	int i, j;
	int n;
	int top = 0, idx = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		nge[arr[i]]++;
	}

	i = 0;
	stack[top++] = i++;
	while(top != 0 && i < n) {
		stack[top++] = i++;
		if (nge[arr[stack[top - 1]]] > nge[arr[stack[top - 2]]]) {
			idx = arr[stack[top - 1]];
			while (top - 2 >= 0 && nge[idx] > nge[arr[stack[top - 2]]]) {
				arr[stack[top - 2]] = idx;
				top--;
			}
			stack[top - 1] = i - 1;
		}
	}

	for (i = 0; i < top; i++) {
		arr[stack[i]] = -1;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}