#include <stdio.h>

int main() {
	int a, i, b, r, g, t, c;
	scanf("%d", &t);
	scanf("%d", &a);
	for (i = 1; i < t; i++) {
		scanf("%d", &b);
		g = a;
		c = b;
		while (b)
		{
			r = g % b;
			g = b;
			b = r;
		}

		printf("%d/%d\n", a/g, c/g);
	}
}