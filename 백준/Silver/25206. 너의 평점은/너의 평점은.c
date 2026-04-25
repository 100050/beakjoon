#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	double a, all, all1, k = 0;
	char str[50], b[2];
	int i;
	
	all = 0;
	all1 = 0;
	for (i = 0; i < 20; i++) {
		scanf("%s %lf %s", str, &a, b);
		
		if (b[0] == 'P') continue;
		
		all += a;
		if (b[0] == 'A') {
			k = 4;
		}
		else if (b[0] == 'B') {
			k = 3;
		}
		else if (b[0] == 'C') {
			k = 2;
		}
		else if (b[0] == 'D') {
			k = 1;
		}
		else if (b[0] == 'F') {
			k = 0;
		}
		if (b[1] == '+') {
			k += 0.5;
		}

		all1 += k * a;
	}
	
	printf("%lf", all1 / all);

	return 0;
}