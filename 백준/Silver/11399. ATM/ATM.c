#include <stdio.h>
#include <stdlib.h>

int* arr2;
void merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			arr2[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			arr2[k++] = arr[l];
	}

	for (i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void mergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int n, i, t;
	int* arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	arr2 = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0, n-1);
	t = 0;
	for (i = 0; i < n; i++) {
		t += arr[i] * (n - i);
	}
	printf("%d", t);


	free(arr);
	free(arr2);
}