#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[500000][2];

int main() {
	int i;
	int n, top, h;
	long long res;

	top = -1;
	res = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &h);
		
		if (top == -1) {
			stack[++top][0] = h;
			stack[top][1] = 1;
		}
		else {
			while (top >= 0 && stack[top][0] < h) {
				res += stack[top][1];
				top--;
			}
			
			if (top == -1) {
				stack[++top][0] = h;
				stack[top][1] = 1;
			}
			else if (stack[top][0] == h) {
				res += stack[top][1];
				stack[top][1]++;
				if (top > 0)
					res++;
			}
			else if (stack[top][0] > h) {
				stack[++top][0] = h;
				stack[top][1] = 1;
				res++;
			}
		}
	}

	printf("%lld\n", res);
	
	return 0;
}