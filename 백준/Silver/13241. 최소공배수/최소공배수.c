#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

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
	long long a, b, c;

	scanf("%lld %lld", &a, &b);
	c = a > b ? func(a, b) : func(b, a);
	printf("%lld", a * b / c);
}