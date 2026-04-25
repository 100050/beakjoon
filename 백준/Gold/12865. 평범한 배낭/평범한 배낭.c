#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int v;
	int w;
} Arr;


int main() {
	int n, k;
	int* top;
	int* bottom;
	Arr* arr;

	scanf("%d %d", &n, &k);
	arr = malloc(sizeof(Arr) * (n+1));
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].w, &arr[i].v);
	}
	top = (int*)malloc(sizeof(int) * (k+1));
	bottom = (int*)malloc(sizeof(int) * (k+1));
	memset(top, 0, sizeof(int) * (k+1));
	memset(bottom, 0, sizeof(int) * (k + 1));
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i].w > j) {
				bottom[j] = top[j];
			}
			else {
				bottom[j] = top[j] > top[j-arr[i].w] + arr[i].v ? top[j] : top[j - arr[i].w] + arr[i].v;
			}
		}
		int* tmp = top;
		top = bottom;
		bottom = tmp;
	}

	printf("%d", top[k]);
	free(top);
	free(bottom);
	free(arr);
}