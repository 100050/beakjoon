#include <stdio.h>
#include <stdlib.h>
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int binsearch(int data[], int n, int key) {
	int low, high;
	int mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {            //탐색 성공
			return mid;
		}
		else if (key < data[mid]) {        //탐색 범위를 아래쪽으로
			high = mid - 1;
		}
		else if (key > data[mid]) {        //탐색 범위를 위쪽으로
			low = mid + 1;
		}
	}
	return -1;                            //탐색 실패
}

int main() {
	int n, m, i,a;
	int* arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		if (binsearch(arr, n, a) != -1) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	free(arr);
}