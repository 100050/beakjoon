#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long func(long long a, long long b) {
	long long r;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return b;
}

int main() {
	long long n, i, num, min, a, b;
	long long* arr;
	
	scanf("%lld", &n);
	arr = (long long*)malloc(sizeof(long long) * n);
	scanf("%lld\n%lld", &a, &b);
	arr[0] = b - a;
	min = b-a;
	a = b;
	for (i = 2; i < n; i++) {
		scanf("%lld", &b);
		arr[i - 1] = b - a;
		if (min > arr[i - 1])
			min = func(min, arr[i - 1]);
		else if (min <= arr[i - 1])
			min = func(arr[i - 1], min);

		a = b;
	}
	num = 0;
	for (i = 0; i < n-1; i++) {
		num += arr[i] / min - 1;
	}


	printf("%lld", num);

	free(arr);
	return 0;
}