#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long arr;
	long long arr2;
} Arr;

int main() {
	long long n, k, i, j, max;
	scanf("%lld %lld", &n, &k);
	Arr* arr;
	arr = (Arr*)malloc(sizeof(Arr) * n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[i].arr);
		arr[i].arr2 = 0;
	}
	for (i = 0; i < k; i++) {
		arr[k-1].arr2 += arr[i].arr;
	}
	max = arr[k - 1].arr2;
	for (i = k; i < n; i++) {
		arr[i].arr2 = arr[i].arr + arr[i-1].arr2 - arr[i-k].arr;

		if (arr[i].arr2 > max)
			max = arr[i].arr2;
		//printf("%lld\n", arr[i].arr2);
	}
	printf("%lld", max);

	free(arr);
}