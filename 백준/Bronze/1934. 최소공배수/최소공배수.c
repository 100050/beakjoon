#include <stdio.h>

int main() {
	int a, i, b, r, g, t;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		g = a * b;
		while (b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		g /= a;

		printf("%d\n", g);
	}
}