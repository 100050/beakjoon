#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}
int main() {
	int n, i, j, max, r, mid, h, l;
	int* x;
	int* arr_x; 
	int* dx;
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);
	dx = (int*)malloc(sizeof(int) * n);
	arr_x = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		arr_x[i] = x[i];
	}
	qsort(arr_x, n, sizeof(int), compare);
	max = arr_x[n - 1];
	i = 0;
	for (j = 0; j < n; j++) {
		arr_x[i] = arr_x[j];
		if (j != n - 1 && arr_x[j] != arr_x[j + 1]) i++;
		if (arr_x[j] == max) break;
	}
	r = i+1;
	for (i = 0; i < n; i++) {
		l = 0;
		h = r;
		while (l <= h) {
			mid = (l + h) / 2;
			if (x[i] == arr_x[mid]) {            //탐색 성공
				dx[i] = mid;
				break;
			}
			else if (x[i] < arr_x[mid]) {        //탐색 범위를 아래쪽으로
				h = mid - 1;
			}
			else if (x[i] > arr_x[mid]) {        //탐색 범위를 위쪽으로
				l = mid + 1;
			}
		}
		/*for (j = 0; j < n; j++) {
			if (arr_x[j] == x[i]) {
				dx[i] = j;
			}
		}*/
	}

	for (i = 0; i < n; i++) {
		printf("%d ", dx[i]);
	}

	free(dx);
	free(x);
	free(arr_x);
}