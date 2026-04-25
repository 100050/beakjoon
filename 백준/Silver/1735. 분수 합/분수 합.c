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
	long long a[3], b[3], c, d, e;

	scanf("%lld %lld", &a[1], &b[1]);
	scanf("%lld %lld", &a[2], &b[2]);
	c = b[1] > b[2] ? func(b[1], b[2]) : func(b[2], b[1]);
	d = (a[1] * b[2] + a[2] * b[1]) / c;
	e = b[1] * b[2] / c;
	c = d > e ? func(d, e) : func(e, d);
	e /= c;
	d /= c;
	printf("%lld %lld", d, e);
}