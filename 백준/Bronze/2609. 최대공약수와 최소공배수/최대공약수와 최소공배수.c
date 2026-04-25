#include <stdio.h>

int main() {
	int a, b, r, l, g;
	scanf("%d %d", &a, &b);
	l = a * b;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	g = a;
	l /= g;

	printf("%d\n%d", g, l);
}