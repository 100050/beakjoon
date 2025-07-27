#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100000][2];

int main() {
	int i;
	int n, top, w, h, in;
	int res;

	top = -1;
	res = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &in);
		
		w = 1;
		if (top == -1) {
			stack[++top][0] = in;
			stack[top][1] = w;
		}
		else {
			// 작다면
			h = 2e+9;
			while (top >= 0 && stack[top][0] > in) {
				if (h > stack[top][0])
					h = stack[top][0];
				w += stack[top][1];
				top--;

				if (h * (w - 1) > res)
					res = h * (w - 1);
			}
			
			if (top == -1) {
				stack[++top][0] = in;
				stack[top][1] = w;
			}
			// 같다면
			else if (stack[top][0] == in) {
				stack[top][1] += w;
			}
			// 크다면
			else if (stack[top][0] < in) {
				stack[++top][0] = in;
				stack[top][1] = w;
			}
			// 2 1 4 5 1 3 3
			// 1 3
			// 5 2
			if (res < stack[top][0] * stack[top][1]) {
				res = stack[top][0] * stack[top][1];
			}

		}
	}

	w = 0, h = 2e+9;
	while (0 <= top) {
		w += stack[top][1];

		if (h > stack[top][0])
			h = stack[top][0];
		if (res < h * w)
			res = h * w;

			//printf("%d : %d, %d\n", top, h, w);
		top--;
	}

	printf("%d\n", res);
	
	return 0;
}