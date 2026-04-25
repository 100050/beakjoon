#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	long n, m, nt, mt, ntt, mtt, t, i, j;
	scanf("%ld %ld", &n, &m);
	nt = 0;
	mt = 0;
	ntt = 0;
	mtt = 0;
	i = 5;
	j = 2;
	while (n >= i || n >= j) {
		nt += n / i;
		i *= 5;
		ntt += n / j;
		j *= 2;
	}
	i = 5;
	j = 2;
	while (n-m >= i || n-m >= j) {
		mt += (n-m) / i;
		i *= 5;
		mtt += (n-m) / j;
		j *= 2;
	}
	i = 5;
	j = 2;
	while (m >= i || m >= j) {
		mt += m / i;
		i *= 5;
		mtt += m / j;
		j *= 2;
	}
	if (nt - mt < ntt - mtt) t = nt - mt;
	else t = ntt - mtt;
	printf("%ld", t);
}